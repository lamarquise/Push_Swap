/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 17:53:33 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// my plan is to change every time i compare Content Values
	// to be a comparison of Index, will see if it works...
#include "push_swap.h"

// no i need to do the Stack Management WAAAAY better
int		ft_partition(t_sorting *all, int id, int size)
{
	int		pivot;
	int		part_size;
	int		rot_count;
	t_nlist	*stack;	// i don't think i want this actually...

	int		ret1;		// for testing, may be tmp


	// this is tmp till i make a pre-Partition
	if (id == 1 && all->stack_b == NULL)
		return (1);

	//	printf("---- Now in Partition ---- TESTING\n"); 

	rot_count = 0;
	part_size = 0;
//	pivot = ft_get_mean(all, id, size);	// no idea if rigth args
	pivot = ft_get_median(all, id, size);	// no idea if rigth args

	//	printf("pivot = %d, size = %d\n", pivot, size);
	//	ft_print_both_stacks(all);
	while (size)
	{
		// not very elegant but...
		if (id == 0)
			stack = all->stack_a;
		else if (id == 1)
			stack = all->stack_b;

		//	printf("in Partition loop, stack content: %d\n", *((int*)stack->index));
		// shit Pascal's solution is really elegant...
		if ((id == 0 && stack->index <= pivot) \
			|| (id == 1 && stack->index > pivot))
		{
			ret1 = ft_wr_push(all, id + 'a' );
			if (ret1 != 1)
				printf("Partition push ret1: %d\n", ret1);
			++part_size;
		}
		else if ((id == 0 && stack->index > pivot) \
				|| (id == 1 && stack->index <= pivot))
		{
			ret1 = ft_wr_rotate(all, id + 'a');
			if (ret1 != 1)
				printf("Partition rotate ret1: %d\n", ret1);
			++rot_count;
		}
		--size;
	}

	//	printf("--- end of Partion ---\n");
	//	ft_print_both_stacks(all);
	// do i need to unrotate?

	while (rot_count)
	{
		ret1 = ft_wr_reverse_rotate(all, id + 'a');
		if (ret1 != 1)
			printf("Partition reverse rotate ret1: %d\n", ret1);
		--rot_count;
	}
	return (part_size);
}


// part_size is the Number of elems pushed to other list
// A is 0 and B is 1
int		ft_my_quick_sort(t_sorting *all, int id, int size)
{
	int	part_size;

	//	printf("---- Now in QS ----- size = %d, ID: %c\n", size, id + 'A');
	//	ft_print_both_stacks(all);
	if (size < 4)
	{
		// apply some sort of minisort that can handle 2 or 3 numbers
		ft_minisort(all, id, size);
		//	printf("in QS, smaller than 4, ID = %c\n", id + 'A');
		//	ft_print_both_stacks(all);
	}
	else
	{
		// OK SO THIS SHIT ISN'T WORKING!!!!!!!!!
		part_size = ft_partition(all, id, size);
		//	printf("in QS, not smaller than 4, part size: %d, ID: %c\n", part_size, id + 'A');
		//	ft_print_both_stacks(all);
		// i think part size is the size of the new parts
		ft_my_quick_sort(all, 0, id ? part_size : size - part_size);
		ft_my_quick_sort(all, 1, id ? size - part_size : part_size);

	}

	// ONCE Size < 4 has been reached, the Recursion Ends!!!!

	return (1);
}


	// should i be reverse Rotating in First Partiton???? I think NO
int		ft_first_partition(t_sorting *all, int size)
{
	int	c;
	int	pivot;
	int	part_size;

	int	ret1;

	c = 0;
	part_size = 0;
		// change to get_median...
//	pivot = ft_get_mean(all, 0, size);
	pivot = ft_get_median(all, 0, size);
	while (c < size)
	{
		if (all->stack_a->index <= pivot)
		{
			ret1 = ft_wr_push(all, 'a');
			if (ret1 != 1)
				printf("First Partition push ret1: %d\n", ret1);
			++part_size;
		}
		else if (all->stack_a->index > pivot)
		{
			ret1 = ft_wr_rotate(all, 'a');
			if (ret1 != 1)
				printf("First Partition rotate ret1: %d\n", ret1);
		}
		++c;
	}

	return (part_size);
}


// we can make it an int and return 1 or whatever if we want later...
int		ft_start_push_swap(t_sorting *all, int size)
{
	int	part_size;

	// may change these to look at indexes... rather than values?
	// but other than that, could keep them here?
	if (ft_is_sorted(all->stack_a))
		return (1);
	else if (ft_is_reverse_sorted(all->stack_a) && !ft_rev_sort(all, size))
		return (0);
	else if (size < 4 && !ft_minisort(all, 0, size))
		return (0);
	else
	{
		part_size = ft_first_partition(all, size);
		//	printf("Start Push Swap, part_size: %d\n", part_size);

		//	printf("--- Partitioned stacks in Starting Push Swap\n");
		//	ft_print_both_stacks(all);

		ft_my_quick_sort(all, 0, size - part_size);
		ft_my_quick_sort(all, 1, part_size);
	}
	return (1);
}



