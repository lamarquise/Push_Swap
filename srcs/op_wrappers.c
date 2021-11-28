/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:53:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:24:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wr_swap(t_sorting *all, char id)
{
	if (!all)
		return (0);
	if (id == 'a' && ft_op_swap(&all->stack_a))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(1)))
			return (0);
		++all->size_op;
		return (1);
	}
	else if (id == 'b' && ft_op_swap(&all->stack_b))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(5)))
			return (0);
		++all->size_op;
		return (1);
	}
	else if (id == 'c' && ft_op_swap_both(&all->stack_a, &all->stack_b))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(8)))
			return (0);
		++all->size_op;
		return (1);
	}
	return (0);
}

int	ft_wr_push_p2(t_sorting *all)
{
	int		result;

	if (!all)
		return (0);
	result = ft_op_push_to_from(&all->stack_b, &all->stack_a);
	if (result != 1)
		return (result);
	if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(4)))
		return (0);
	++all->size_op;
	--all->size_a;
	++all->size_b;
	return (1);
}

int	ft_wr_push(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
	if (id == 'b')
	{
		result = ft_op_push_to_from(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(0)))
			return (0);
		++all->size_op;
		++all->size_a;
		--all->size_b;
	}
	else if (id == 'a')
		return (ft_wr_push_p2(all));
	return (1);
}

int	ft_all_push_to_from(t_sorting *all, char id)
{
	int		ret1;

	if (!all)
		return (0);
	if (id == 'a')
	{
		while (all->stack_b != NULL)
		{
			ret1 = ft_wr_push(all, 'b');
			if (ret1 != 1)
				return (ret1);
		}
	}
	else if (id == 'b')
	{
		while (all->stack_a != NULL)
		{
			ret1 = ft_wr_push(all, 'a');
			if (ret1 != 1)
				return (ret1);
		}
	}
	else
		return (2);
	return (1);
}
