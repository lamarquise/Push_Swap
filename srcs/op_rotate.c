/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:53:53 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:26:01 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// Is Secure!

int	ft_op_rotate(t_nlist **stack)
{
	t_nlist	*first;
	t_nlist	*last;

	if (!stack)
		return (0);
	first = *stack;
	last = *stack;
	if (!*stack || !first->next)
		return (2);
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
	return (1);
}

int	ft_op_reverse_rotate(t_nlist **stack)
{
	t_nlist	*first;
	t_nlist	*last;
	t_nlist	*new_last;

	if (!stack)
		return (0);
	first = *stack;
	last = *stack;
	new_last = NULL;
	if (!*stack || !first->next)
		return (2);
	while (last->next)
	{
		new_last = last;
		last = last->next;
	}
	last->next = first;
	*stack = last;
	new_last->next = NULL;
	return (1);
}

int	ft_op_rotate_both(t_nlist **stack_a, t_nlist **stack_b)
{
	int		ret1;

	if (!stack_a || !stack_b)
		return (0);
	ret1 = ft_op_rotate(stack_a);
	if (ret1 != 1)
		return (ret1);
	ret1 = ft_op_rotate(stack_b);
	if (ret1 != 1)
		return (ret1);
	return (1);
}

int	ft_op_reverse_rotate_both(t_nlist **stack_a, t_nlist **stack_b)
{
	int		ret1;

	if (!stack_a || !stack_b)
		return (0);
	ret1 = ft_op_reverse_rotate(stack_a);
	if (ret1 != 1)
		return (ret1);
	ret1 = ft_op_reverse_rotate(stack_b);
	if (ret1 != 1)
		return (ret1);
	return (1);
}
