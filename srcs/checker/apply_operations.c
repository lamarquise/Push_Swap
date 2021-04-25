/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:23:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/25 06:31:21 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// tentatively just in Checker.h for now
#include "checker.h"


		// eventually there will also be some way of passing the Ops from STD IN
		// or do i just need a read for that?
int		ft_apply_ops(t_list **stack_a, t_list **stack_b)
{

	if (!stack_a || !stack_b)
		return (0);
	
//	ft_swap(stack_a);

//	ft_push_to_from(stack_b, stack_a);

//	ft_push_both(stack_a, stack_b);


//	ft_rotate(stack_a);

	ft_reverse_rotate(stack_a);


// ok so here is where i read from the Standard Input... I will prolly have to parse
// what i read to some degree, make sure it's not giberish
// i think i can use my GNL!!!






	return (1);
}
