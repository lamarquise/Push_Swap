/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_codes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:49:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 17:46:35 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Is Secure!

int		ft_check_add_code(char *line, t_list **op_codes, char **valid_tab)
{
	t_list	*new;
	char	*nstr;

	if (!line || !op_codes || !valid_tab)
		return (0);	
	if (!ft_strcmp_to_strtab(line, valid_tab))
		return (0);

	// I hate that lstadd_back returns a void, makes it way harder to check
	// if everything has gone right...
	// may need to use a "new" var and do lstnew & dup separately...


		// this is a fucking shit show, if strdup fails, it returns NULL
		// so lstnew still gets created but it's contents is NULL.
		// but what happens if strdup works but lstnew does not, we have a leak!
	nstr = ft_strdup(line);
	if (!nstr)
		return (0);
	new = ft_lstnew(nstr);
	if (!new)
	{
		free(nstr);
		return (0);
	}

//	ft_lstadd_back(op_codes, ft_lstnew(ft_strdup(line)));
	ft_lstadd_back(op_codes, new);
	return (1);
}

	// seems secure and leak free, did it the same ways as Cub3d
int		ft_parse_op_codes(t_list **op_codes)
{
	int		i;
	int		ret;
	char	*line;
	char	**valid_tab;
	
	if (!op_codes || *op_codes)
		return (0);
	i = 0;
	ret = 1;
	line = NULL;
	valid_tab = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", " ");
	if (!valid_tab)
		return (0);
	while ((ret = ft_gnl(&line, 0)) > 0)
	{
		if (!ft_check_add_code(line, op_codes, valid_tab))
		{
			ft_scott_free(&line, 0);
			ft_free_strtab(valid_tab);
			return (0);
		}
		ft_scott_free(&line, 0);
		++i;
	}
//	printf("gnl ret: %d\n", ret);
	ft_scott_free(&line, 0);
	ft_free_strtab(valid_tab);
	if (i == 0)		// this is the thing that allows me to know if nothing in STDIN
		return (2);	// in which case we print nothing i think...
	return (1);
}
