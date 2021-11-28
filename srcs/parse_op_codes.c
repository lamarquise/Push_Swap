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

int	ft_check_add_code(char *line, t_list **op_codes, char **valid_tab)
{
	t_list	*new;
	char	*nstr;

	if (!line || !op_codes || !valid_tab)
		return (0);
	if (!ft_strcmp_to_strtab(line, valid_tab))
		return (0);
	nstr = ft_strdup(line);
	if (!nstr)
		return (0);
	new = ft_lstnew(nstr);
	if (!new)
	{
		free(nstr);
		return (0);
	}
	ft_lstadd_back(op_codes, new);
	return (1);
}

int	ft_parse_op_codes_p2(t_list **op_codes, char **valid_tab)
{
	int		ret;
	char	*line;

	if (!op_codes || *op_codes || !valid_tab || !*valid_tab)
		return (0);
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = ft_gnl(&line, 0);
		if (ret > 0)
		{
			if (!ft_check_add_code(line, op_codes, valid_tab))
			{
				ft_scott_free(&line, 0);
				ft_free_strtab(valid_tab);
				return (0);
			}
		}
		ft_scott_free(&line, 0);
	}
	return (1);
}

int	ft_parse_op_codes(t_list **op_codes)
{
	int		ret;
	char	**valid_tab;

	if (!op_codes || *op_codes)
		return (0);
	valid_tab = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", " ");
	if (!valid_tab)
		return (0);
	ret = ft_parse_op_codes_p2(op_codes, valid_tab);
	if (ret != 1)
	{
		ft_free_strtab(valid_tab);
		return (0);
	}
	ft_free_strtab(valid_tab);
	return (1);
}
