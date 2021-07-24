/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:04:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/23 10:05:22 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// in both for now
#include "both.h"


	// Push A is push from B to A
	// Push B is from A to B

int		ft_op_push_to_from(t_list **stack_to, t_list **stack_from)
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

// basically we want it to move the whole stack over
int		ft_all_push_to_from(t_list **stack_to, t_list **stack_from)
{
	while (*stack_from)
	{
//		printf("in push all to from\n");
		if (!ft_op_push_to_from(stack_to, stack_from))
			return (0);
	}

	// will need to do the thing where we update the Structure data...

	return (1);
}


