/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:25:47 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:36:35 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int		ft_op_swap(t_nlist **stack)
{
	t_nlist	*e1;
	t_nlist	*e2;

	e1 = NULL;
	e2 = NULL;
	if (!stack || !*stack)	// is this correct?
		return (0);
	if ((*stack)->next)
	{
		e1 = *stack;
		e2 = (*stack)->next;
		e1->next = e2->next;
		e2->next = e1;
		*stack = e2;
	}
	return (1);
}

int		ft_op_swap_both(t_nlist **stack_a, t_nlist **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_op_swap(stack_a) || !ft_op_swap(stack_b))
		return (0);

	return (1);
}
