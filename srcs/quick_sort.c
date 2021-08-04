/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 19:42:54 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// no i need to do the Stack Management WAAAAY better
int		ft_partition(t_sorting *all, int id, int size)
{
	int		pivot;
	int		part_size;
	int		rot_count;
	t_list	*stack;	// i don't think i want this actually...

	// this is tmp till i make a pre-Partition
	if (id == 1 && all->stack_b == NULL)
		return (1);

	//	printf("---- Now in Partition ---- TESTING\n"); 

	rot_count = 0;
	part_size = 0;
	pivot = ft_get_mean(all, id, size);	// no idea if rigth args

	//	printf("pivot = %d, size = %d\n", pivot, size);
	//	ft_print_both_stacks(all);
	while (size)
	{
		// not very elegant but...
		if (id == 0)
			stack = all->stack_a;
		else if (id == 1)
			stack = all->stack_b;

		//	printf("in Partition loop, stack content: %d\n", *((int*)stack->content));
		// shit Pascal's solution is really elegant...
		if ((id == 0 && *((int*)stack->content) <= pivot) \
			|| (id == 1 && *((int*)stack->content) > pivot))
		{
			ft_wr_push(all, id + 'a' );
			++part_size;
		}
		else if ((id == 0 && *((int*)stack->content) > pivot) \
				|| (id == 1 && *((int*)stack->content) <= pivot))
		{
			ft_wr_rotate(all, id + 'a');
			++rot_count;
		}
		--size;
	}

	//	printf("--- end of Partion ---\n");
	//	ft_print_both_stacks(all);
	// do i need to unrotate?

	while (rot_count)
	{
		ft_wr_reverse_rotate(all, id + 'a');
		--rot_count;
	}
	return (part_size);
}


// part_size is the Number of elems pushed to other list
// A is 0 and B is 1
void	ft_my_quick_sort(t_sorting *all, int id, int size)
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

	//	return (1);
}


int		ft_first_partition(t_sorting *all, int size)
{
	int	c;
	int	pivot;
	int	part_size;

	c = 0;
	part_size = 0;
	pivot = ft_get_mean(all, 0, size);
	while (c < size)
	{
		if (*((int*)all->stack_a->content) <= pivot)
		{
			ft_wr_push(all, 'a');
			++part_size;
		}
		else if (*((int*)all->stack_a->content) > pivot)
			ft_wr_rotate(all, 'a');
		++c;
	}

	return (part_size);
}


// we can make it an int and return 1 or whatever if we want later...
void	ft_start_push_swap(t_sorting *all, int size)
{
	int	part_size;

	if (ft_is_sorted(all->stack_a))
		return ;
	else if (ft_is_reverse_sorted(all->stack_a))
		ft_rev_sort(all, size);
	else if (size < 4)
		ft_minisort(all, 0, size);
	else
	{
		part_size = ft_first_partition(all, size);
		//	printf("Start Push Swap, part_size: %d\n", part_size);

		//	printf("--- Partitioned stacks in Starting Push Swap\n");
		//	ft_print_both_stacks(all);

		ft_my_quick_sort(all, 0, size - part_size);
		ft_my_quick_sort(all, 1, part_size);
	}
}



