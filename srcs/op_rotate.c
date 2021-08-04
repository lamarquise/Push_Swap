/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:53:53 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 23:55:59 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int		ft_op_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

//	printf("in Rotate 1\n");
	first = NULL;
	last = NULL;
	if (!stack)
		return (0);

//	printf("in Rotate 2\n");
	first = *stack;
	last = *stack;

//	printf("in Rotate 3\n");
//	if (!first || !first->next)
	if (!first->next)
		return (2);

//	printf("in Rotate 4\n");
	// doesn't happen if only 1 elem
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
//	printf("in Rotate end\n");
	return (1);
}

int		ft_op_reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

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

int		ft_op_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_op_rotate(stack_a) || !ft_op_rotate(stack_b))
		return (2);

	return (1);
}

int		ft_op_reverse_rotate_both(t_list **stack_a, t_list **stack_b)
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
