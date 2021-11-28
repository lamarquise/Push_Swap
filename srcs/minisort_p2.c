/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:23:52 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_median_p2(t_nlist *stack, int size)
{
	int		c;
	int		min;
	int		max;
	long	total;

	if (!stack)
		return (0);
	c = 0;
	total = 0;
	min = INTMAX;
	max = 0;
	while (c < size)
	{
		if (stack->index < min)
			min = stack->index;
		if (stack->index > max)
			max = stack->index;
		total += stack->index;
		stack = stack->next;
		++c;
	}
	return ((min + max - 1) / 2);
}

int	ft_get_median(t_sorting *all, int id, int size)
{
	t_nlist	*stack;

	if (!all)
		return (0);
	stack = NULL;
	if (id == 0 && all->stack_a)
		stack = all->stack_a;
	else if (id == 1 && all->stack_b)
		stack = all->stack_b;
	else
		return (0);
	return (ft_get_median_p2(stack, size));
}

void	ft_threesort_p2(t_sorting *all, t_nlist *stack)
{
	if (stack->next->index < stack->index \
		&& stack->next->index > stack->next->next->index)
		ft_wr_rotate(all, 'a');
	else if (stack->index > stack->next->index \
		&& stack->next->index < stack->next->next->index)
		ft_wr_swap(all, 'a');
	else if (stack->next->index < stack->index \
		&& stack->index > stack->next->next->index)
		ft_wr_rotate(all, 'a');
}

int	ft_threesort(t_sorting *all, int id, int size)
{
	t_nlist	*stack;

	if (!all || id != 0)
		return (0);
	stack = all->stack_a;
	if (size == 3)
	{
		while (!(stack->index < stack->next->index \
				&& stack->next->index < stack->next->next->index))
		{
			if (stack->next->index > stack->index \
				&& stack->next->index > stack->next->next->index)
				ft_wr_reverse_rotate(all, 'a');
			else
				ft_threesort_p2(all, stack);
			stack = all->stack_a;
		}
	}
	else if (size == 2 && stack->index > stack->next->index)
		ft_wr_swap(all, 'a');
	return (1);
}
