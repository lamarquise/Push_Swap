/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/03 12:38:17 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// now we need a few functions
	// one that gets the median (we can maybe do some cleaver math
		// along the way for that
	// one that "splits" whatever that means
	// one that partitions...


	// might need to be void...
	// p_size is partition size of a so 
	// ok so i stole his id being an int
		// A is 0 and B is 1
void	ft_b_quick_sort(t_sorting *all, int id, int size)
{

// Ok so this is a Quick sort, what do we do?
// We partition it before calling it (do that in main)
// we Apply Minisort if the thing we are sorting is <= 3
// We part again and apply quick sort to both
// But those are in both A and B stacks, not sure how that works
	// maybe it's the Recursive shit that just works things out...
	int		part_size;

	printf("---- Now in QS ----- size = %d\n", size);
	ft_print_both_stacks(all);
	if (size < 4)
	{
		printf("in QS, smaller than 4\n");
		// apply some sort of minisort that can handle 2 or 3 numbers
		ft_minisort(all, id, size);
	}
	else
	{
		// OK SO THIS SHIT ISN'T WORKING!!!!!!!!!
		part_size = ft_partition(all, id, size);
		printf("in QS, not smaller than 4, part size: %d\n", part_size);
		// i think part size is the size of the new parts
		ft_b_quick_sort(all, 0, id ? part_size : size - part_size);
		ft_b_quick_sort(all, 1, id ? size - part_size : part_size);

	}

	// ONCE Size < 4 has been reached, the Recursion Ends!!!!

//	return (1);
}

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

	printf("---- Now in Partition ----\n"); 
	part_size = 0;
	pivot = ft_get_mean(all, id, size);	// no idea if rigth args

	printf("pivot = %d, size = %d\n", pivot, size);
	ft_print_both_stacks(all);
	while (size)
	{
		// not very elegant but...
		if (id == 0)
			stack = all->stack_a;
		else if (id == 1)
			stack = all->stack_b;

		// shit Pascal's solution is really elegant...
		if ((id == 0 && *((int*)stack->content) <= pivot) \
			|| (id == 1 && *((int*)stack->content) > pivot))
		{
			// push
			ft_wr_push(all, id + 'a');
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
	
	return (part_size);
}


// do i have to unrotate it at some point?




// Old versions that aren't really in use but there are a few things
// I figured out that i can copy over

	// Ok so the way he did it was with args arr, l, r
	// and then use counters i and j
	//
int		ft_my_quick_sort(t_sorting *all, int l, int r)
{

	// Lets start by implementing his way of doing things
	// but like it's not gonna be recursive for now...


	int		i;	// not sure i even need these...
	int		j;
	int		p;	// as in pivot
	t_list	*tmp_a;
	t_list	*tmp_b;

	i = -1;
	j = 0;
		// this should be the value of the last elem...
	p = *((int*)ft_lstlast_pointer(all->stack_a)); // like i'm trying to dereference the whole thing....
	tmp_a = all->stack_a;
	tmp_b = all->stack_b;
	
	// just to shut it up for now
	l = 0;
	r = 0;

	i = 0;	// cuz the way i do it makes more sense this way.
	// will want a better condition, one that takes l and r into account
	while (i < all->info_a->size)
	{
		if (*((int*)tmp_a->content) < p)
		{
			// sercure later
			ft_wr_push(all, 'b');
		}
		else if (*((int*)tmp_a->content) > p)
		{
			ft_wr_rotate(all, 'a');

		}
		++i;

	}
	ft_print_both_stacks(all);
		// secure? will i even keep it?
	ft_all_push_to_from(all, 'a');
	return (1);
}


	// so we want to pass the stoping point of the 
int		ft_a_quick_sort(t_sorting *all, int p_index)
{
	int		i;
	int		p;

// this doesn't work if we put it in the loop...
	printf("size A: %d, size B: %d\n", all->info_a->size, all->info_b->size);
	if (all->info_a->size == 3)
		ft_sort_end_cases(all, &all->stack_a, 'a');
	else if (all->info_b->size == 3)
		ft_sort_end_cases(all, &all->stack_b, 'b');

	i = 0;
//	p = *((int*)ft_lstlast_pointer(all->stack_a));
	p = *((int*)ft_pointer_at_index(all->stack_a, p_index));
//	printf("Pivot Value: %d, stack_a size: %d, p_index: %d\n", p, all->info_a->size, p_index);

	// this doesn't work cuz we update the size of A with the Wrapper
	// funcs, need a different condition...
//	while (i < all->info_a->size)
	// I don't love this condition but i think it should work...
//	while (*((int*)all->stack_a->content) != p && all->info_a->size > 3)
	while (*((int*)all->stack_a->content) != p)
	{
//		printf("Value of current elem of A: %d\n", *((int*)all->stack_a->content));
//		printf("value of i in loop: %d\n", i);
		if (*((int*)all->stack_a->content) < p)
		{
//			printf("sort smaller so push\n");
			// sercure later
			ft_wr_push(all, 'b');
		}
		else if (*((int*)all->stack_a->content) > p)
		{
//			printf("sort bigger so rotate\n");
			ft_wr_rotate(all, 'a');

		}
//		++i;
		ft_print_both_stacks(all);

	}


	if (p_index < all->size_total)
	{
		// we are pushing the Pivot so we can reverse rotate back
		// the old stuff
		p_index = all->size_total - all->info_a->size;
		ft_wr_push(all, 'b');
		while (all->info_a->rot > 0)
			ft_wr_reverse_rotate(all, 'a');
	}
	else
	{
		p_index = all->size_total - all->info_a->size;
		all->info_a->rot = 0;
	}

		// secure? will i even keep it?
	ft_all_push_to_from(all, 'a');


//	ft_print_both_stacks(all);

	// not sure what i'm doing here but we need some recursion so...
	if (p_index != 0)
		return (ft_a_quick_sort(all, p_index));
	// we can't just push all back from B
	// we also should't just return for the recursion
	// i think we should call it, and then do a push back and a reverse
	// rotate?

	return (1);
}






