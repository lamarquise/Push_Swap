/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:12:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Is Secure!

int	ft_is_reverse_sorted(t_nlist *stack)
{
	t_nlist	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
		if (*((int *)tmp->content) < *((int *)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_rev_sort(t_sorting *all)
{
	while (all->size_a > 3)
	{
		ft_wr_reverse_rotate(all, 'a');
		ft_wr_push(all, 'a');
	}
	ft_threesort(all, 0, all->size_a);
	ft_all_push_to_from(all, 'a');
	return (1);
}

int	ft_sort_by_index(t_sorting *all)
{
	t_nlist	*c;
	t_nlist	*t;
	int		i;
	int		j;

	if (!all)
		return (0);
	i = all->size_total;
	c = all->stack_a;
	while (i--)
	{
		c->index = 1;
		t = all->stack_a;
		j = all->size_total;
		while (j--)
		{
			if (*((int *)t->content) < *((int *)c->content))
				++c->index;
			else if (*((int *)t->content) == *((int *)c->content) && t != c)
				return (0);
			t = t->next;
		}
		c = c->next;
	}
	return (1);
}
