/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:04:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/02 13:48:58 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"


	// Push A is push from B to A
	// Push B is from A to B

int		ft_op_push_to_from(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp_from;

	tmp_from = NULL;		// necessary?
	if (!stack_from || !stack_to)
		return (ft_error_msg("ERROR: OP Push missing a pointer to stack\n", 0));

	tmp_from = *stack_from;
	if (tmp_from == NULL)	// overly explicit
		return (2);			// means nothing happened

	*stack_from = (*stack_from)->next;

	tmp_from->next = *stack_to;
	*stack_to = tmp_from;
		

	return (1);
}

/*
	// might need to call the wrapper not the Op directly cuz we would want
	// to produce the Op codes in STDOUT
	// and we don't need this func in Checker cuz it's only allowed to run
	// the auth funcs, so would be a whole bunch of PA or PBs anyway...
// basically we want it to move the whole stack over
int		ft_all_push_to_from(t_list **stack_to, t_list **stack_from, char id)
{ while (*stack_from)
	{
s/		printf("in push all to from\n");
//		if (!ft_op_push_to_from(stack_to, stack_from))
		if (!ft_op_push_to_from(stack_to, stack_from))
			return (0);
	}

	// will need to do the thing where we update the Structure data...

	return (1);
}
*/



