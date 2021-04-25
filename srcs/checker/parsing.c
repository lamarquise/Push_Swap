/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/25 03:03:38 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// keep it in both for now...
#include "both.h"

	// this is gonna be the wraper...

/*
	// so far this does nothing...
int		*ft_av_to_ints(char **av)
{
	int		*tab;

	tab = NULL;

	return (tab);
}
*/

	// i expect a lot of the stuff in there now is gonna get moved later...
	// should i be creating *tab sooner? like in main?
int		ft_parser(char **av, int **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (av[i])
	{
		++i;
	}
	if (!(*tab = ft_memalloc(sizeof(int *) * (i - 1))))
		return (0);
	i = 0;

	// this might be where we want to do some checks...

	while (av[i + 1])
	{
		(*tab)[i] = ft_atoi(av[i + 1]);
		++i;
	}

	// some free if it fails...

	return (i);
}





