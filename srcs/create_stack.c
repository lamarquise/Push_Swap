/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 16:58:13 by ericlazo         ###   ########.fr       */
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
void	ft_print_lstelem_int(t_nlist *elem)
{
	ft_putnbrnl((int *)(elem->content));
}
*/


	// what if we never reallocated a copy of the ints in Tab, 
	// we just point to them
	// so each elem points to an int in tab. when it comes to
	// freeing at the end
	// we just have to free tab!!!! not the contents of the Linked list!

int		ft_create_stack(t_nlist **stack, int **int_tab, int size)
{
	t_nlist	*new;
	int		i;

	if (!stack || !int_tab || !*int_tab)// may need to double check this condition...
		return (0);
	new = NULL;
	i = 0;
	while (i < size)
	{
		// leave this for now, but could do like in Cub3D, cleaner...
		new = ft_nlstnew(&((*int_tab)[i]), 0);// start by filling index with 0
		if (!new)
			return (0);
		// if lstnew fails i need to free the list not new
		if (!ft_nlstadd_back(stack, new))
			return (0);		// I think i can do this
		++i;
	}

	return (1);
}


		// i think i still need this weird free func cuz of how 
			// we deal with content, like it's in int_tab...
int		ft_free_list_elems(t_nlist **stack)
{
	t_nlist	*tmp;

	if (!stack)
		return (1);		// if nothing to do we gucci
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	// free (stack too?) not sure...
 	return (1);
}
