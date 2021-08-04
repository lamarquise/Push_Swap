/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_qs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/03 14:34:58 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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






