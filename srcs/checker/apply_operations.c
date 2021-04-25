/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:23:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/25 07:16:05 by ericlazo         ###   ########.fr       */
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


	// testing GNL

	// start by writing to the Standard Output: fd=1
	ft_putstr("this is a test\nIt contiues on a second line\n");

	int		ret;
	char	*line;
	char	*clip;

	ret = 1;
	line = NULL;
	clip = NULL;		// this could be my segfault issue, figure out how to use gnl properly and WRITE IT DOWN!!!!!!
			// 16 is # chars to read and 0 is Stdin fd
	while ((ret = gnl(&line, &clip, 16, 0)) > 0)
	{
		printf("GNL Line: |%s|", line);
	}

	return (1);
}
