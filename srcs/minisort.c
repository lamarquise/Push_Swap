/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:23:52 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_minisort_a_p2(t_sorting *all, int size)
{
	ft_wr_rotate(all, 'a');
	ft_minisort_a(all, size - 1);
	ft_wr_reverse_rotate(all, 'a');
}

int	ft_minisort_a(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;

	if (size == 2 && all->stack_a->index > all->stack_a->next->index)
		ft_wr_swap(all, 'a');
	else if (size == 3)
	{
		a = all->stack_a->index;
		b = all->stack_a->next->index;
		c = all->stack_a->next->next->index;
		if (a < b && b < c)
			return (1);
		else if (a > b)
		{
			if (all->stack_b->index < all->stack_b->next->index)
				ft_wr_swap(all, 'c');
			else
				ft_wr_swap(all, 'a');
		}
		else
			ft_minisort_a_p2(all, size);
		return (ft_minisort_a(all, size));
	}
	return (1);
}

int	ft_minisort_b(t_sorting *all, int size)
{
	if (size == 1)
	{
		if (all->stack_a->index > all->stack_a->next->index)
			ft_wr_swap(all, 'a');
		ft_wr_push(all, 'b');
	}
	else
	{
		if (all->stack_b->index < all->stack_b->next->index)
		{
			if (all->stack_a->index > all->stack_a->next->index)
				ft_wr_swap(all, 'c');
			else
				ft_wr_swap(all, 'b');
		}
		ft_wr_push(all, 'b');
		return (ft_minisort_b(all, size - 1));
	}
	return (1);
}

int	ft_minisort(t_sorting *all, int id, int size)
{
	if (!all)
		return (0);
	if (id == 0)
	{
		if (size != all->size_a)
			ft_minisort_a(all, size);
		else
			ft_threesort(all, 0, size);
	}
	else if (id == 1)
		ft_minisort_b(all, size);
	else
		return (0);
	return (1);
}
