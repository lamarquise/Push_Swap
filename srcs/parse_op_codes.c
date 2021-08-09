/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 20:40:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

//		printf("Parser iter %d, GNL Line: |%s|\n", i, line);

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





