/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 05:53:53 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/25 06:19:20 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// in both for now
#include "both.h"

int		ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = NULL;
	last = NULL;
	if (!stack)
		return (0);

	first = *stack;
	last = *stack;

	if (!last->next)
		return (1);

	// doesn't happen if only 1 elem
	while (last->next)
		last = last->next;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
	return (1);
}

int		ft_reverse_rotate(t_list **stack)
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

	if (!last->next)
		return (1);

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

int		ft_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_rotate(stack_a) || !ft_rotate(stack_b))
		return (0);

	return (1);
}

int		ft_reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_reverse_rotate(stack_a) || !ft_reverse_rotate(stack_b))
		return (0);

	return (1);
}
