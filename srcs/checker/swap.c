/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:25:47 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/25 05:02:34 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// both tentatively....
#include "both.h"


	// could be interesting to keep track of the Size of Stack A and B at all times
	// That way i don't have to count everytime that is necessary?
	// would i need to Count?
	// Won't for now...

	// IDK... seems right?

int		ft_swap(t_list **stack)
{
	t_list	*e1;
	t_list	*e2;

	e1 = NULL;
	e2 = NULL;
	if (!stack || !*stack)
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

int		ft_swap_both(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (0);

	if (!ft_swap(stack_a) || !ft_swap(stack_b))
		return (0);

	return (1);
}


