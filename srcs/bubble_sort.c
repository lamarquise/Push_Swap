/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:33:05 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/22 17:39:08 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It's a Bubble sort, it's stupid, we're gonna do it in a while loop...

#include "push_swap.h"

int		ft_bubble_sort(t_sorting *all)
{
	int		bol;

	bol = 1;

//	printf("we are doing my Bubble Sort\n");

	// Ok so we want to compare top and 2nd, and any time you swap you go
	// back 1 from B.

	// here our goal is to get everything from stack A to Stack B
// if i wanted to futher optimize, i could use a counter that track how
// close to the bottom of Stack A the loop has gotten, and it stops if it
// has made it to the last element, that way it doesn't move it's whole self
// over to Stack B and i don't have to then Re move it from B to A...
	while (all->stack_a->next)
	{
		// pointer to an int

		if (*((int*)(all->stack_a->content)) > *((int*)(all->stack_a->next->content)))
		{
//			printf("Bubble Sort Swap\n");
			// second is smaller than first so we swap
			// must then retreive all from Stack B
			ft_wr_swap(all, &all->stack_a, 'a');
		//	ft_all_push_to_from(&all->stack_a, &all->stack_b);
			ft_op_push_to_from(&all->stack_a, &all->stack_b);
		}
		else if (*((int*)(all->stack_a->content)) < *((int*)(all->stack_a->next->content)))
		{
//			printf("Bubble Sort Push\n");
			// first is smallest so we push to B
			if (!ft_op_push_to_from(&all->stack_b, &all->stack_a))
				return (0);
		}

//		printf("end of loop in bubble sort\n");
//		ft_print_mysort_all(all);
	}

//	printf("Bubble Sort all back to A\n");
	// now we need to return all from stack B to Stack A
	ft_all_push_to_from(&all->stack_a, &all->stack_b);
	return (1);
}
