/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ints_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:12 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// Is Secure :)

int	ns(char *str)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (ft_findchar("0123456789", str[i]) > -1 \
			&& (!str[i + 1] || str[i + 1] == ' '))
			++numbers;
		++i;
	}
	return (numbers);
}

int	ft_check_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') \
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		else if (ft_findchar("+- 0123456789", str[i]) == -1)
			return (0);
		++i;
	}
	return (1);
}

int	ft_fill_int_tab_p2(char *str, int *neg, int a)
{
	while (str[a] == ' ')
		++a;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			*neg = -1;
		++a;
	}
	return (a);
}

int	ft_fill_int_tab(char *str, int **int_tab)
{
	int		a;
	int		i;
	int		neg;
	long	tmp;

	a = 0;
	i = 0;
	neg = 1;
	tmp = 0;
	while (str[a])
	{
		a = ft_fill_int_tab_p2(str, &neg, a);
		while (str[a] >= '0' && str[a] <= '9')
		{
			tmp = tmp * 10 + (str[a] - 48);
			++a;
		}
		tmp *= neg;
		if (tmp < INTMIN || tmp > INTMAX)
			return (0);
		(*int_tab)[i++] = tmp;
		neg = 1;
		tmp = 0;
	}
	return (1);
}

int	ft_split_ints(char *str, int **int_tab)
{
	int	a;
	int	size;

	if (!str)
		return (0);
	if (!str[0])
		return (-1);
	if (!int_tab || !ft_check_str(str))
		return (-2);
	a = 0;
	size = ns(str);
	if (size < 1)
		return (-3);
	*int_tab = ft_memalloc(sizeof(int *) * size);
	if (!*int_tab)
		return (-4);
	if (!ft_fill_int_tab(str, int_tab))
		return (-5);
	return (size);
}
