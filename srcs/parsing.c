/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 18:09:37 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// Is Secure!

int	ft_check_is_number_full_str(char *str)
{
	int		i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] < '0' \
			|| str[i + 1] > '9'))
			return (0);
		else if (ft_findchar("+-0123456789", str[i]) == -1)
			return (0);
		++i;
	}
	return (1);
}

int	ft_parser(char **str, int **int_tab, int size)
{
	if (!str || !int_tab)
		return (0);
	if (size == 1)
		size = ft_split_ints(str[0], int_tab);
	else
	{
		*int_tab = ft_memalloc(sizeof(int *) * size);
		if (!*int_tab)
			return (0);
		size = 0;
		while (str[size])
		{
			if (!ft_check_is_number_full_str(str[size]))
				return (0);
			if (!ft_satoi(str[size], &(*int_tab)[size]))
				return (0);
			++size;
		}
	}
	return (size);
}
