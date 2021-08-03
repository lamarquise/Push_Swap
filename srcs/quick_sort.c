/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/03 22:31:24 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// no i need to do the Stack Management WAAAAY better
	// like if i move through the list, it should actually move through
	// the list
int		ft_partition(t_sorting *all, int id, int size)
{
	int		pivot;
	int		part_size;
	t_list	*stack;		// i don't think i want this actually...

		// this is tmp till i make a pre-Partition
	if (id == 1 && all->stack_b == NULL)
		return (1);

//	printf("---- Now in Partition ---- TESTING\n"); 
	
/*	stack = NULL;
	int		ret1;
	if (id == 0)
		stack = all->stack_a;
	printf("stack: %d\n", *((int*)stack->content));
	ft_print_both_stacks(all);
	ret1 = ft_wr_push(all, id + 'a');
	printf("ret1: %d\n", ret1);
	if (id == 0)
		stack = all->stack_a;
	printf("stack: %d\n", *((int*)stack->content));
	ft_print_both_stacks(all);
*/

	part_size = 0;
	pivot = ft_get_mean(all, id, size);	// no idea if rigth args

	printf("pivot = %d, size = %d\n", pivot, size);
//	ft_print_both_stacks(all);
	while (size)
	{
		// not very elegant but...
		if (id == 0)
			stack = all->stack_a;
		else if (id == 1)
			stack = all->stack_b;

//		printf("in Partition loop, stack content: %d\n", *((int*)stack->content));
		// shit Pascal's solution is really elegant...
		if ((id == 0 && *((int*)stack->content) <= pivot) \
			|| (id == 1 && *((int*)stack->content) > pivot))
		{
			// push
			ft_wr_push(all, id + 'a' );
			++part_size;
		}
		else if ((id == 0 && *((int*)stack->content) > pivot) \
			|| (id == 1 && *((int*)stack->content) <= pivot))
		{
			// rotate
			ft_wr_rotate(all, id + 'a');
		}
		--size;
	}
	
//	printf("--- end of Partion ---\n");
//	ft_print_both_stacks(all);
	// do i need to unrotate?
	return (part_size);
}


// do i have to unrotate it at some point?


	// part_size is the Number of elems pushed to other list
		// A is 0 and B is 1
void	ft_my_quick_sort(t_sorting *all, int id, int size)
{
	int		part_size;

	printf("---- Now in QS ----- size = %d, ID: %c\n", size, id + 'A');
	ft_print_both_stacks(all);
	if (size < 4)
	{
		// apply some sort of minisort that can handle 2 or 3 numbers
		ft_minisort(all, id, size);
		printf("in QS, smaller than 4, ID = %c\n", id + 'A');
		ft_print_both_stacks(all);
	}
	else
	{
		// OK SO THIS SHIT ISN'T WORKING!!!!!!!!!
		part_size = ft_partition(all, id, size);
		printf("in QS, not smaller than 4, part size: %d\n", part_size);
		ft_print_both_stacks(all);
		// i think part size is the size of the new parts
		ft_my_quick_sort(all, 0, id ? part_size : size - part_size);
		ft_my_quick_sort(all, 1, id ? size - part_size : part_size);

	}

	// ONCE Size < 4 has been reached, the Recursion Ends!!!!

//	return (1);
}






