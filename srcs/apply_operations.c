/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:23:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:09:03 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_apply_ops(t_sorting *all, t_list **op_codes)
{
	int		ret;

	ret = 0;
	if (!all || !op_codes)
		return (0);
	
	// i think it's just gonna end up being a giant if forest

	while (*op_codes)
	{
		if (!ft_strcmp((char*)(*op_codes)->content, "pa") \
			&& !ft_op_push_to_from(&all->stack_a, &all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "pb") \
			&& !(ret = ft_op_push_to_from(&all->stack_b, &all->stack_a)))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "sa") \
			&& !ft_op_swap(&all->stack_a))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "sb") \
			&& !ft_op_swap(&all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "ss") \
			&& !ft_op_swap_both(&all->stack_a, &all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "ra") \
			&& !ft_op_rotate(&all->stack_a))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "rb") \
			&& !ft_op_rotate(&all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "rr") \
			&& !ft_op_rotate_both(&all->stack_a, &all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "rra") \
			&& !ft_op_reverse_rotate(&all->stack_a))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "rrb") \
			&& !ft_op_reverse_rotate(&all->stack_b))
			return (0);
		else if (!ft_strcmp((char*)(*op_codes)->content, "rrr") \
			&& !ft_op_reverse_rotate_both(&all->stack_a, &all->stack_b))
			return (0);

	// or we could do the clearing of the list later... IDK we'll figure
	// þ out later...
//		if (!ft_lstdel_first())
		*op_codes = (*op_codes)->next;
	}

	return (1);
}
