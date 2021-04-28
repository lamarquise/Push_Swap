/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 02:29:05 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 02:29:21 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

	// could do a void
	// this function is kinda useless...
int		ft_init_stack_info(t_stack_info *info, int size)
{
	if (!info)
		return (0);
//	info->max = -2147483648;	// instead we assign it the first val of the int_tab
//	info->min = 2147483647;		// instead, so there can be no confusion
//	info->mean_a = 0;
//	info->mean_b = 0;

		// this works for Info B but not A, i mean it would just get replaced...
	info->max = INTMIN;	// instead we assign it the first val of the int_tab
	info->min = INTMAX;		// instead, so there can be no confusion
	info->size = size;
	info->rot = 0;
	return (1);
}

int		ft_prep_stack_info(t_stack_info *info, int *int_tab)
{
	int		i;

	i = 0;

	// could call init_stack HERE if main is short on lines...

	if (!info || !int_tab)
		return (0);

		// finding min and max
	info->min = int_tab[i];
	info->max = int_tab[i];
	while (int_tab[i])
	{
		if (int_tab[i] < info->min)
			info->min = int_tab[i];
		if (int_tab[i] > info->max)
			info->max = int_tab[i];
	}
	info->mean = info->min + (info->max - info->min)/2;
	return (1);
}


	// for now assuming int tab is Valid, like no doubles or Nums larger than an int.
	// we are also assuming the tab has more than 1 elem...
/*
int		ft_prep_mysort_info(t_mysort_info *info_all, int *int_tab)
{
	int		i;

	i = 0;

	// could call init_mysort HERE if main is short on lines...


	if (!info_all || !int_tab)
		return (0);

		// finding min and max
	info_all->min_a = int_tab[i];
	info_all->max_a = int_tab[i];
	while (int_tab[i])
	{
		if (int_tab[i] < info_all->min_a)
			info_all->min_a = int_tab[i];
		if (int_tab[i] > info_all->max_a)
			info_all->max_a = int_tab[i];
	}
	info_all->mean_a = info_all->min_a + (info_all->max_a - info_all->min_a)/2;

	return (1);
}
*/
