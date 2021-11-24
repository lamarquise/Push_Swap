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

// Is Secure!

int	ft_op_push_to_from(t_nlist **stack_to, t_nlist **stack_from)
{
	t_nlist	*tmp_from;

	if (!stack_from || !*stack_from || !stack_to)
		return (0);
	tmp_from = *stack_from;
	if (tmp_from == NULL)
		return (2);
	*stack_from = (*stack_from)->next;
	tmp_from->next = *stack_to;
	*stack_to = tmp_from;
	return (1);
}
