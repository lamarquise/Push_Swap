/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:23:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:09:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_apply_ops_p2(t_sorting *all, t_list *tmp)
{
	if (!all || !tmp)
		return (0);
	if (!ft_strcmp((char *)(tmp)->content, "ss"))
		ft_op_swap_both(&all->stack_a, &all->stack_b);
	else if (!ft_strcmp((char *)(tmp)->content, "ra"))
		ft_op_rotate(&all->stack_a);
	else if (!ft_strcmp((char *)(tmp)->content, "rb"))
		ft_op_rotate(&all->stack_b);
	else if (!ft_strcmp((char *)(tmp)->content, "rr"))
		ft_op_rotate_both(&all->stack_a, &all->stack_b);
	else if (!ft_strcmp((char *)(tmp)->content, "rra"))
		ft_op_reverse_rotate(&all->stack_a);
	else if (!ft_strcmp((char *)(tmp)->content, "rrb"))
		ft_op_reverse_rotate(&all->stack_b);
	else if (!ft_strcmp((char *)(tmp)->content, "rrr"))
		ft_op_reverse_rotate_both(&all->stack_a, &all->stack_b);
	return (1);
}

int	ft_apply_ops(t_sorting *all, t_list **op_codes)
{
	t_list	*tmp;

	if (!all || !op_codes)
		return (0);
	tmp = *op_codes;
	while (tmp)
	{
		if (!ft_strcmp((char *)(tmp)->content, "pa"))
			ft_op_push_to_from(&all->stack_a, &all->stack_b);
		else if (!ft_strcmp((char *)(tmp)->content, "pb"))
			ft_op_push_to_from(&all->stack_b, &all->stack_a);
		else if (!ft_strcmp((char *)(tmp)->content, "sa"))
			ft_op_swap(&all->stack_a);
		else if (!ft_strcmp((char *)(tmp)->content, "sb"))
			ft_op_swap(&all->stack_b);
		else if (!ft_apply_ops_p2(all, tmp))
			return (0);
		tmp = (tmp)->next;
	}
	return (1);
}
