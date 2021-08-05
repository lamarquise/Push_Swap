/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/05 13:35:04 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// It's in both, this part of the Parsing is universal
#include "both.h"

int		ft_parser(char **av, int **tab)
{
	int		i;
	char	**arg_string;

//	printf("parsing test 1\n");

//	printf("in parser, int tab pointer address val: %p\n", tab);
//	printf("in parser, int tab pointer val: %p\n", *tab);

	// you need to secure av!!!!!
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

	// absolutely need to run more checks to make sure they are all numbers..
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

//	ft_print_inttab(*tab, i);
//	printf("in parser, int tab pointer val: %p\n", *tab);
//	printf("-------- done parsing into tab ------\n");
	return (i);
}

	// May need to put this in a separate file for just Checker
	// parsing, better for compilation.

int		ft_parse_op_codes(t_list **op_codes)
{

	// basically i want to use GNL to grab whatever is in the STDOUT
	// and put it in a linked list called OP_CODES

	int		ret;
	char	*line;
	char	**valid_tab;
	int		i;
	i = 0;
	
	ret = 1;
	line =  NULL;
	valid_tab = NULL;
	if (!(valid_tab = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", " ")))
		return (ft_error_msg("ERROR: Failed to create Vaild_Tab\n", 0));
//	valid_tab = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", " ");
//	ft_print_strtab(valid_tab);
	if (*op_codes)
		return (ft_error_msg("ERROR: Op Codes list already exists\n", 0));

	while ((ret = ft_gnl(&line, 0)) > 0)
	{
		// some function that puts the line in a linked list elem

		printf("Parser iter %d, GNL Line: |%s|\n", i, line);

		// ok so i want a func that makes sure the string is
		// one of the authorized ones
		// i want a func that takes that string and puts it in a linked
		// list...

		// ok so I'm gonna do the checking and adding to list all in one func
		if (!ft_check_add_code(line, op_codes, valid_tab))
			return (ft_error_msg("ERROR: Check & Add Code failed\n", 0));		// but like also free stuff?
		ft_scott_free(&line, 0);
		++i;
	}
	ft_scott_free(&line, 0);

//	printf("Done Parsing Op Codes in Parser\n");

//	ft_lstprint(*op_codes);

	return (1);
}

	// have i added too many layers, like i could prolly just have called
	// strcmp_to_strtab...
int		ft_check_add_code(char *line, t_list **op_codes, char **valid_tab)
{
	// what do i need to check?
	// have a list of valid codes and cross reference, again like Cub3D
	if (!line || !op_codes || !valid_tab)
		return (0);	
	if (!ft_strcmp_to_strtab(line, valid_tab))
		return (ft_error_msg("ERROR: strcmp to strtab failed\n", 0));
//	if (!ft_lstadd_back(op_codes, ft_lstnew(ft_strdup(line))))
//		return (ft_error_msg("ERROR: Failed to add and create new op code elem\n", 0));

	// I hate that lstadd_back returns a void, makes it way harder to check
	// if everything has gone right...
	// may need to use a "new" var and do lstnew & dup separately...
	ft_lstadd_back(op_codes, ft_lstnew(ft_strdup(line)));
	return (1);
}





