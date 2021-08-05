/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/05 21:10:12 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

	// both of these go in the Libft
		// Maybe after this projec tho, focus for now...

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


	// what if we never reallocated a copy of the ints in Tab, we just point to them
	// so each elem points to an int in tab. when it comes to freeing at the end
	// we just have to free tab!!!! not the contents of the Linked list!

int		ft_create_stack(t_list **stack, int **int_tab, int size)
{
	t_list	*new;
	int		i;

	if (!stack || !int_tab || !*int_tab)// may need to double check this condition...
		return (0);
	new = NULL;
	i = 0;
	// while ((*tab)) wouldn't work, right? NOPE
//	while ((*tab))
	while (i < size)
	{
		// these do the same thing but 2nd is less ugly
		// tab[i] does not work, increments the wrong pointer.
		new = ft_lstnew(&((*int_tab)[i]));
	//	new = ft_lstnew((*tab)++);

	//	printf("int in tab: %d, i=%d\n", (*tab)[i], i);

		// not sure if this is secure, check and test when sober...
		// just tab[i]?
	// this might have been the problem, need to use a counter to inc
//		ft_lstadd_back(stack, ft_lstnew(&((*tab)[i])));
//		ft_lstadd_back(stack, ft_lstnew((*tab)++));
		ft_lstadd_back(stack, new);
		// do actually need this... ugh
		++i;
	}
//	printf("create stack test 2 end\n");

	return (1);
}
