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

/*
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
	//	if (!(arg_string = ft_split(av[0], " ")))
		if (!(arg_string = ft_simple_split(av[0])))
			return (0);
		i = 0;
		while (arg_string[i])
			++i;
		if (!(*int_tab = ft_memalloc(sizeof(int *) * i)))
			return (ft_scott_free(arg_string, 0));
		i = 0;
		while (arg_string[i])
		{
			if (!ft_satoi(arg_string[i], &(*int_tab)[i]))
			{
				ft_free_strtab(arg_string);
				return (0);
			}
//			(*int_tab)[i] = ft_atoi(arg_string[i]);
			++i;
		}
	//	ft_print_strtab(arg_string);
		ft_free_strtab(arg_string);
	//	free(arg_string);	// now done in  free_strtab... might keep...
	}
	else
	{
		if (!(*int_tab = ft_memalloc(sizeof(int *) * (i))))
			return (0);
		i = 0;
		while (av[i])
		{
			if (!ft_satoi(av[i], &(*int_tab)[i]))
				return (0);
//				return (ft_error_msg("there is an error\n", 0));
		//	(*int_tab)[i] = ft_atoi(av[i]);
			++i;
		}
	}
	return (i);
}
*/



// New Parser, this one will be a generic Int List converter...

/*

	We got 2 options, a list of int in a single arg
	or a list of ints each in their own arg

	Ideally use a regular Atoi, and do the checking externally
*/


//int		ft_check_is_number_str(char *str, int end)
int		ft_check_is_number_full_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		else if (ft_findchar("+-0123456789", str[i]) == -1)
			return (0);
		++i;
	}
	return (1);
}

	// Str could be a single string or many
	// same as before, int_tab gets invoked above, then send a pointer
int		ft_parser(char **str, int **int_tab, int size)
{
	if (!str || !int_tab)	// is this how you secure AV ???
		return (0);
	if (size == 1)
	{	// A single String needs to be cut up
//		printf("in size 1 parser\n");
		ft_putstr(str[0]);
//		printf("in parser str: |%s|\n", str[0]);
		size = ft_split_ints(str[0], int_tab);
//		printf("in parser size: %d\n", size);
//		ft_print_inttab(*int_tab, size);
	}
	else
	{	// Multiple strings
		*int_tab = ft_memalloc(sizeof(int *) * size);
		if (!*int_tab)
			return (0);
		size = 0;
		while (str[size]) 
		{
			if (!ft_check_is_number_full_str(str[size]))
				return (0);
			// i do actually need to use satoi, check if INTMIN or INTMAX...
			if (!ft_satoi(str[size], &(*int_tab)[size]))
				return (0);
	//		(*int_tab)[size] = ft_atoi(str[size]);
			++size;
		}
	}
	return (size);
}








