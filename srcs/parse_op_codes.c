/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:40:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

	// have i added too many layers, like i could prolly just have called
	// strcmp_to_strtab...
int		ft_check_add_code(char *line, t_list **op_codes, char **valid_tab)
{
	t_list	*new;

	// what do i need to check?
	// have a list of valid codes and cross reference, again like Cub3D
	if (!line || !op_codes || !valid_tab)
		return (0);	
	if (!ft_strcmp_to_strtab(line, valid_tab))
	{
//		printf("line: |%s|\n", line);
		return (0);
	}

	// I hate that lstadd_back returns a void, makes it way harder to check
	// if everything has gone right...
	// may need to use a "new" var and do lstnew & dup separately...
	if (!(new = ft_lstnew(ft_strdup(line))))
		return (0);

//	ft_lstadd_back(op_codes, ft_lstnew(ft_strdup(line)));
	ft_lstadd_back(op_codes, new);
	return (1);
}

	// seems secure and leak free, did it the same ways as Cub3d
int		ft_parse_op_codes(t_list **op_codes)
{
	int		ret;
	char	*line;
	char	**valid_tab;
	int		i;
	i = 0;
	
	if (!op_codes)
		return (0);
	ret = 1;
	line =  NULL;
	valid_tab = NULL;
	if (!(valid_tab = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", " ")))
		return (0);
//	ft_print_strtab(valid_tab);
	if (*op_codes)
		return (0);

	while ((ret = ft_gnl(&line, 0)) > 0)
	{
		// ok so I'm gonna do the checking and adding to list all in one func
		if (!ft_check_add_code(line, op_codes, valid_tab))
		{
			// free op codes, free line, free valid tab?
			ft_scott_free(&line, 0);
			ft_free_strtab(valid_tab);
			return (0);		// but like also free stuff?
		}
		ft_scott_free(&line, 0);
		++i;
	}
	ft_scott_free(&line, 0);
	ft_free_strtab(valid_tab);
	return (1);
}





