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

// Is Secure!
	// like i'm not gonna add a bunch of if-checks, there's no leaks, good enough

	// needs to be much shorter...
int	ft_get_median(t_sorting *all, int id, int size)
{
	int		c;
	int		min;
	int		max;
	long	total;
	t_nlist	*stack;

	if (!all)
		return (0);
	c = 0;
	total = 0;
	min = INTMAX;
	max = 0;
	if (id == 0 && all->stack_a)
		stack = all->stack_a;
	else if (id == 1 && all->stack_b)
		stack = all->stack_b;
	else
		return (0);	// maybe excessive...
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

	// func too long...
int	ft_threesort(t_sorting *all, int id, int size)
{
	t_nlist	*stack;

//	printf("in Threesort\n");
	if (!all || id != 0) // i mean, i guess, but really this doesn't even get used...
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
			else if (stack->next->index < stack->index \
				&& stack->next->index > stack->next->next->index)
				ft_wr_rotate(all, 'a');
			else if (stack->index > stack->next->index \
				&& stack->next->index < stack->next->next->index)
				ft_wr_swap(all, 'a');
			else if (stack->next->index < stack->index \
				&& stack->index > stack->next->next->index)
				ft_wr_rotate(all, 'a');
			stack = all->stack_a;
		}
	}
	else if (size == 2 && stack->index > stack->next->index)
		ft_wr_swap(all, 'a');
	return (1);
}

	// The Minisorts A and B are for sorting Partitions of size 3 or less
	// Stolen and Adapted Directly from Pascal, thanks
// Func too long...
int	ft_minisort_a(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;

	if (size == 2 && all->stack_a->index \
		> all->stack_a->next->index)
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
			if (all->stack_b->index \
				< all->stack_b->next->index)
				ft_wr_swap(all, 'c');
			else
				ft_wr_swap(all, 'a');
		}
		else
		{
			ft_wr_rotate(all, 'a');
			ft_minisort_a(all, size - 1);
			ft_wr_reverse_rotate(all, 'a');
		}
		return (ft_minisort_a(all, size));
	}
	return (1);
}

	// this one we could improve a bit, by using the Push back to A
	// as a tool for sorting...
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
