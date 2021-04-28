/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 01:02:43 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// do i also need to #include "push_swap.h"?

#include "both.h"


	// both of these go in the Libft

	// does it need to return an int?
int		ft_print_inttab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putnbrnl(tab[i++]);
	return (1);
}

/*
void	ft_print_lstelem_int(t_list *elem)
{
	ft_putnbrnl((int *)(elem->content));
}
*/


	// in order for create_stack to be generic, we are going to assume
	// av has already been trimed the first time we get it, so we start after
	// av[0], rather at av[1].

	// no actually, we are going to wrap create stack in a func that takes av
	// and turns it into a table of ints.


	// what if we never reallocated a copy of the ints in Tab, we just point to them
	// so each elem points to an int in tab. when it comes to freeing at the end
	// we just have to free tab!!!! not the contents of the Linked list!

int		ft_create_stack(t_list **stack, int **tab, int size)
{
	t_list	*new;
	int		i;

	// testing
//	ft_print_inttab(*tab, size);

	if (size)
		i = 0;

	new = NULL;
	i = 0;
	if (!stack || !tab || !*tab)		// may need to double check this condition...
		return (0);
	// while ((*tab)) wouldn't work, right? NOPE
//	while ((*tab))
	while (i < size)
	{
		// these do the same thing but 2nd is less ugly
		// tab[i] does not work, increments the wrong pointer.
	//	new = ft_lstnew(&((*tab)[i]));
	//	new = ft_lstnew((*tab)++);

	//	printf("int in tab: %d, i=%d\n", (*tab)[i], i);

		// not sure if this is secure, check and test when sober...
		// just tab[i]?
		ft_lstadd_back(stack, ft_lstnew((*tab)++));
	//	ft_lstadd_back(stack, new);
		// do actually need this... ugh
		++i;
	}
	return (1);
}