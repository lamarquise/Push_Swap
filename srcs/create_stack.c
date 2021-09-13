/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 01:44:30 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"


	// NOT IN FINAL PUSH TO VOG
	// does it need to return an int?
int		ft_print_inttab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putnbrnl(tab[i++]);
	return (1);
}


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
		// like Cub3d so should be fine?
		if (!ft_nlstadd_back(stack, ft_nlstnew(&((*int_tab)[i]), 0)))
			return (0);
		++i;
	}

	return (1);
}
