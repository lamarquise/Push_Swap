/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/24 09:31:17 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// keep it in both for now...
#include "both.h"


	// i expect a lot of the stuff in there now is gonna get moved later...
	// should i be creating *tab sooner? like in main?
int		ft_parser(char **av, int **tab)
{
	int		i;
	char	**arg_string;

//	printf("parsing test 1\n");


	arg_string = NULL;
	i = 0;
	if (!tab)
		return (0);
	while (av[i])
	{
		++i;
	}

	// This is the event where we use ARG so 1 string to hold all the 
	// Numbers OR there is only 1 Number
	// maybe put this whole bit in it's own func...
	if (i == 2)
	{
		// So we split the ARG string
		if (!(arg_string = ft_split(av[1], " ")))
			return (0);
		// now we have to atoi it...
		i = 0;
		while (arg_string[i])
			++i;
		if (!(*tab = ft_memalloc(sizeof(int *) * i)))
			return (0);
		i = 0;
		while (arg_string[i])
		{
			(*tab)[i] = ft_atoi(arg_string[i]);
			++i;
		}
	}
	else
	{
		if (!(*tab = ft_memalloc(sizeof(int *) * (i - 1))))
			return (0);
		i = 0;

		// this might be where we want to do some checks...

		while (av[i + 1])
		{
			(*tab)[i] = ft_atoi(av[i + 1]);
			++i;
		}
	}
	// some free if it fails...

	return (i);
}


int		ft_parse_op_codes(t_list *op_codes)
{

	// basically i want to use GNL to grab whatever is in the STDOUT
	// and put it in a linked list called OP_CODES

	int		ret;
	char	*line;
	
	ret = 1;
	line =  NULL;
	if (op_codes)
		return (0);

	while ((ret = ft_gnl(&line, 0)) > 0)
	{
		// some function that puts the line in a linked list elem

		printf("GNL Line: |%s|\n", line);
	}

	return (1);
}





