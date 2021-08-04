/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:25:47 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 22:53:12 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int		ft_op_swap(t_list **stack)
{
	t_list	*e1;
	t_list	*e2;

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

	// NVM all Op funcs just take Stacks...
//int		ft_op_swap_both(t_sorting *all)

int		ft_op_swap_both(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_op_swap(stack_a) || !ft_op_swap(stack_b))
		return (0);

	return (1);
}


