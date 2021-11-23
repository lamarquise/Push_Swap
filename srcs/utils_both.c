/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 18:09:45 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// do not love the name, would prefere these sort of funcs come from or be
	// put in the Libft...

#include "both.h"

// Is Secure! (nothing allocated)

// this might be another one i should add to Libft...
// basically i want a func þ compares a string to a table to strings

int	ft_strcmp_to_strtab(char *input, char **tab)
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
int	ft_is_sorted(t_nlist *stack)
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

int	ft_satoi(const char *str, int *num)
{
	int		a;
	long	ret;
	int		neg;

	a = 0;
	ret = 0;
	neg = 1;
	if (str[a] == 43 || str[a] == 45)
	{
		if (str[a] == 45)
			neg = -1;
		++a;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		ret = ret * 10 + (str[a] - 48);
		++a;
	}
	if (str[a] != '\0')
		return (0);
	ret *= neg;
	if (ret > INTMAX || ret < INTMIN)
		return (0);
	*num = ret;
//	printf("end of satoi num: %d\n", *num);
	return (1);
}
