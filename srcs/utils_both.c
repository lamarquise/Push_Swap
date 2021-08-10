/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:25:36 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// do not love the name, would prefere these sort of funcs come from or be
	// put in the Libft...

#include "both.h"


// this might be another one i should add to Libft...
// basically i want a func þ compares a string to a table to strings

int		ft_strcmp_to_strtab(char *input, char **tab)
{
	int		i;

	if (!input || !tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(input, tab[i]))
			return (1);
		++i;
	}


	return (0);
}


		// should i change to look only at index or will i not do the
			// pre sorting in Checker????
int		ft_is_sorted(t_nlist *stack)
{
	t_nlist	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
			// i think this is good enough
		if (*((int*)tmp->content) > *((int*)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}

	return (1);
}


