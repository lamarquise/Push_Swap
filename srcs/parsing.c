/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 19:59:44 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// THIS is where i might add the extra Pre Sorting if i do that

	// It's in both, this part of the Parsing is universal
#include "both.h"


 	// using a dumb name but could change it and add to libft later...
int		ft_free_int_tab(int **int_tab, int size)
{
	int	i;

	if (!int_tab)
		return (1);		// so it doesn't crash if no int tab
	i = 0;

	while (i < size)
	{
			// Is this good enough ????
			// IDK if this does what i want...
	//	free((*int_tab)[i]);


	// This crashes shit, don't do it...
//		free((int_tab)[i]);

		++i;
	}

	// or is it just
	free(*int_tab);		// ????

	return (1);
}


	// need to make sure values is between intmin and intmax
		// for all numbs in list
		// possibly in a dif func...
	// Seems secure...
int		ft_parser(char **av, int **int_tab, int i)
{
	char	**arg_string;

	arg_string = NULL;
	if (!av || !int_tab)	// is this how you secure AV ???
		return (0);

	if (i == 1)
	{
		// is secure
		if (!(arg_string = ft_split(av[0], " ")))
			return (0);
		i = 0;
		while (arg_string[i])
			++i;
		if (!(*int_tab = ft_memalloc(sizeof(int *) * i)))
			return (ft_scott_free(arg_string, 0));
		i = 0;
		while (arg_string[i])
		{
			(*int_tab)[i] = ft_atoi(arg_string[i]);
			++i;
		}
		ft_scott_free(arg_string, 0);
	}
	else
	{
		if (!(*int_tab = ft_memalloc(sizeof(int *) * (i))))
			return (0);
		i = 0;
		while (av[i])
		{
			(*int_tab)[i] = ft_atoi(av[i]);
			++i;
		}
	}
	return (i);
}

