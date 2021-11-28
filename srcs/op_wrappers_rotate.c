/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:53:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:24:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_wr_rotate_p2(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
	if (id == 'b')
	{
		result = ft_op_rotate(&all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(6)))
			return (0);
		++all->size_op;
	}
	else if (id == 'r')
	{
		result = ft_op_rotate_both(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(9)))
			return (0);
		++all->size_op;
	}
	return (1);
}

int	ft_wr_rotate(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
	if (id == 'a')
	{
		result = ft_op_rotate(&all->stack_a);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(2)))
			return (0);
		++all->size_op;
	}
	else
		return (ft_wr_rotate_p2(all, id));
	return (1);
}

int	ft_wr_reverse_rotate_p2(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
	if (id == 'b')
	{
		result = ft_op_reverse_rotate(&all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(7)))
			return (0);
		++all->size_op;
	}
	else if (id == 'c')
	{
		result = ft_op_reverse_rotate_both(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(10)))
			return (0);
		++all->size_op;
	}
	return (1);
}

int	ft_wr_reverse_rotate(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
	if (id == 'a')
	{
		result = ft_op_reverse_rotate(&all->stack_a);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(3)))
			return (0);
		++all->size_op;
	}
	else
		return (ft_wr_reverse_rotate_p2(all, id));
	return (1);
}
