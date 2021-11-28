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

int	ft_print_inttab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putnbrnl(tab[i++]);
	return (1);
}

int	ft_create_stack(t_nlist **stack, int **int_tab, int size)
{
	t_nlist	*new;
	int		i;

	if (!stack || !int_tab || !*int_tab)
		return (0);
	new = NULL;
	i = 0;
	while (i < size)
	{
		if (!ft_nlstadd_back(stack, ft_nlstnew(&((*int_tab)[i]), 0)))
			return (0);
		++i;
	}
	return (1);
}
