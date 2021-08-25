/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:04:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:25:45 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

	// Push A is push from B to A
	// Push B is from A to B

int		ft_op_push_to_from(t_nlist **stack_to, t_nlist **stack_from)
{
	t_nlist	*tmp_from;

//	tmp_from = NULL;		// necessary?
	if (!stack_from || !*stack_from || !stack_to)
		return (0);

	tmp_from = *stack_from;
	if (tmp_from == NULL)	// overly explicit
		return (2);			// means nothing happened

	*stack_from = (*stack_from)->next;

	tmp_from->next = *stack_to;
	*stack_to = tmp_from;

	return (1);
}



