/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:53:53 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:35:13 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int		ft_op_rotate(t_nlist **stack)
{
	t_nlist	*first;
	t_nlist	*last;

	first = NULL;
	last = NULL;
	if (!stack)
		return (0);

	first = *stack;
	last = *stack;

	// Yea we really need to figure this out...
//	if (!first || !first->next)
	if (!first->next)
		return (2);

	// doesn't happen if only 1 elem
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
//	printf("in Rotate end\n");
	return (1);
}

int		ft_op_reverse_rotate(t_nlist **stack)
{
	t_nlist	*first;
	t_nlist	*last;
	t_nlist	*new_last;

	first = NULL;
	last = NULL;
	new_last = NULL;
	if (!stack)
		return (0);

	first = *stack;
	last = *stack;

		// ie if there is only one elem
//	if (!first->next)
	if (!first || !first->next)
		return (2);

	// doesn't happen if only 1 elem
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

int		ft_op_rotate_both(t_nlist **stack_a, t_nlist **stack_b)
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
	//if (!ft_op_rotate(stack_a) || !ft_op_rotate(stack_b))
	//	return (2);

	return (1);
}

int		ft_op_reverse_rotate_both(t_nlist **stack_a, t_nlist **stack_b)
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
//	if (!ft_op_reverse_rotate(stack_a) || !ft_op_reverse_rotate(stack_b))
//		return (2);

	return (1);
}
