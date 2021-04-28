/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:04:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 01:02:29 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// in both for now
#include "both.h"


	// Push A is push from B to A
	// Push B is from A to B

int		ft_push_to_from(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp_from;

	tmp_from = NULL;		// necessary?
	if (!stack_from || !stack_to)
		return (0);

	tmp_from = *stack_from;
	if (tmp_from == NULL)	// overly explicit
		return (2);			// means nothing happened

	*stack_from = (*stack_from)->next;

	tmp_from->next = *stack_to;
	*stack_to = tmp_from;
		

	return (1);
}

	// apparently this isn't an operation...

/*
int		ft_push_both(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = NULL;	// necessary?
	tmp_b = NULL;
	if (!stack_a || !stack_b)
		return (0);

	tmp_a = *stack_a;
	tmp_b = *stack_b;

	tmp_a->next = (*stack_b)->next;
	tmp_b->next = (*stack_a)->next;

	*stack_a = tmp_b;
	*stack_b = tmp_a;




	t_list	*tmp;

	tmp = NULL;		// necessary?

	if (!stack_a || !stack_b)
		return (0);

	tmp = *stack_b;

		// Push A
	if (!ft_push_to_from(stack_a, stack_b))
		return (0);

		// Push B
	if (!ft_push_to_from(&tmp, stack_a))
		return (0);


	return (1);
}
*/





