/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:32:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// Same as in QS we are changing all times compare content values with
		// indexes, see if it works
#include "push_swap.h"

int		ft_get_median(t_sorting *all, int id, int size)
{
	int		c;
	int		min;
	int		max;
	long	total;
	t_nlist	*stack;

	if (!all)
		return (0);
	c = 0;
	total = 0;
	min = INTMAX;
	max = 0;
	if (id == 0 && all->stack_a)
		stack = all->stack_a;
	else if (id == 1 && all->stack_b)
		stack = all->stack_b;
	else
		return (0);	// maybe excessive...

	// could just use size, no c, but meh
	while (c < size)
	{
		if (stack->index < min)
			min = stack->index;
		if (stack->index > max)
			max = stack->index; 
		total += stack->index;
		stack = stack->next;
		++c;
	}
//	printf("end of get_mean, total: %ld\n", total);
	return ((min + max - 1) / 2);
}


	// is secure i think
	// may need more clean up
int		ft_get_mean(t_sorting *all, int id, int size)
{
	int		c;
	int		min;
	int		max;
	long	total;
	t_nlist	*stack;

	if (!all)
		return (0);
	c = 0;
	total = 0;
	min = INTMAX;
	max = INTMIN;
	if (id == 0 && all->stack_a)
		stack = all->stack_a;
	else if (id == 1 && all->stack_b)
		stack = all->stack_b;
	else
		return (0);	// maybe excessive...

	while (c < size)
	{
		if (*((int*)stack->content) < min)
			min = *((int*)stack->content);
		if (*((int*)stack->content) > max)
			max = *((int*)stack->content); 
		total += *((int*)stack->content);
		stack = stack->next;
		++c;
	}
//	printf("end of get_mean, total: %ld\n", total);
	return ((int)(total / size));
}


	// this one is a fucking disaster...
		// doesn't actualy do anything for lists of size 2 or 1...

	// Threesort is for when the stack is Empty except 3 values
	// ok i just used the End cases i found from that other guy,
		// seems to be working !?
int		ft_sort_end_case(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;
	char	id;

	int		ret1;	// for TESTING tmp i think

	if (!all)
		return (0);
	id = 'a';
	if (size == 3)
	{
		a = all->stack_a->index;
		b = all->stack_a->next->index;
		c = all->stack_a->next->next->index;
	/*	while (!(a < b && b < c))
		{

		}
	*/
		if (a > b && a < c)
		{
			ret1 = ft_wr_swap(all, id);
			if (ret1 != 1)
				printf("End Case Swap 1 ret1: %d\n", ret1);
		}
		else if (a > b && b > c)
		{
			ret1 = ft_wr_swap(all, id);
			if (ret1 != 1)
				printf("End Case Swap 2 ret1: %d\n", ret1);
			ret1 = ft_wr_reverse_rotate(all, id);
			if (ret1 != 1)
				printf("End Case reverse rotate 1 ret1: %d\n", ret1);
		}
		else if (a > b && b < c)
		{
			ret1 = ft_wr_rotate(all, id);
			if (ret1 != 1)
				printf("End Case rotate 1 ret1: %d\n", ret1);
		} 
		else if (a < b && a < c)
		{
			ret1 = ft_wr_swap(all, id);
			if (ret1 != 1)
				printf("End Case Swap 3 ret1: %d\n", ret1);
			ret1 = ft_wr_rotate(all, id);
			if (ret1 != 1)
				printf("End Case rotate 2 ret1: %d\n", ret1);
		}
		else if (a < b && a > c)
		{
			ret1 = ft_wr_reverse_rotate(all, id);
			if (ret1 != 1)
				printf("End Case reverse rotate 2 ret1: %d\n", ret1);
		}
	}
	else if (size == 2 && all->stack_a->index > all->stack_a->next->index)
		ft_wr_swap(all, 'a');
	return (1);
}



	// The Minisorts A and B are for sorting Partitions of size 3 or less
	// Stolen and Adapted Directly from Pascal, thanks
int		ft_minisort_a(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;

	int		ret1;	// for TESTING may be Tmp

//	printf("--- In Minisort A\n");
	if (size == 2 && all->stack_a->index \
		> all->stack_a->next->index)
	{
		ret1 = ft_wr_swap(all, 'a');
		if (ret1 != 1)
			printf("Minisort A Swap 1 ret1: %d\n", ret1);
	}
	else if (size == 3)
	{
		a = all->stack_a->index;
		b = all->stack_a->next->index;
		c = all->stack_a->next->next->index;
		if (a < b && b < c)
			return (1);
		else if (a > b)
		{
			if (all->stack_b->index \
				< all->stack_b->next->index)
			{
				ret1 = ft_wr_swap(all, 'c');
				if (ret1 != 1)
					printf("Minisort Swap 2 ret1: %d\n", ret1);
			}
			else
			{
				ret1 = ft_wr_swap(all, 'a');
				if (ret1 != 1)
					printf("Minisort Swap 3 ret1: %d\n", ret1);
			}
		}
		else
		{
			ret1 = ft_wr_rotate(all, 'a');
			if (ret1 != 1)
				printf("Minisort A rotate 1 ret1: %d\n", ret1);
			ft_minisort_a(all, size - 1);
			ret1 = ft_wr_reverse_rotate(all, 'a');
			if (ret1 != 1)
				printf("Minisort A reverse rotate 1 ret1: %d\n", ret1);
		}
		return (ft_minisort_a(all, size));
	}
	return (1);
}


	// Here is how you could use Push to optimize a bit more

/*

if in correct order you push all back
if in reverse order (there are 3)

It would work better with 4

if A < B >> C < D
Push A and B SS Push C and D 5 

I can do 11 Ops for 4 in reverse order, not great...

Actually i can do 4 in rev order in 8, that's pretty good
I can do any 4 in B in 9 or less
Shit how did i do it in 8, i can do it in 9....


*/

/*
	// only works for B ?
int		ft_smallest_on_top(t_sorting *all, int id, int size)
{
	int		i;
	int		top;
	t_nlist	*stack;

	if (!all || size < 0 || id != 1)
		return (0);
	if (size == 1)
		return (1);
	i = 1;
	stack = all->stack_b;
	top = stack->index;
	stack = stack->next;
	while (i < size)
	{
		if (top > stack->index)
			return (0);
		stack = stack->next;
		++i;
	}
	return (1);
}

	// only works for B ?
int		ft_largest_on_top(t_sorting *all, int id, int size)
{
	int		i;
	int		top;
	t_nlist	*stack;

	if (!all || size < 0 || id != 1)
		return (0);
	if (size == 1)
		return (1);
	i = 1;
	stack = all->stack_b;
	top = stack->index;
	stack = stack->next;
	while (i < size)
	{
		if (top < stack->index)
			return (0);
		stack = stack->next;
		++i;
	}
	return (1);
}


int		ft_b_quad_sort(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		rot_count;

	if (!all || size != 4)
		return (0);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->next->next->index;
	d = all->stack_b->next->next->next->index;
	rot_count = 0;

//	printf("Larg ret: %d\n", ft_largest_on_top(all, 1, size));

	while (size)
	{
		// not this only if largest on top
		if (size == 3)
			// run regular minisort_b
		else if (ft_smallest_on_top(all, 1, size))
			// push to bottom and sort 3 then rotate and push

		else if (ft_largest_on_top(all, 1, size))
		{
			// push to a from b and regurlar minisort
			ft_wr_push(all, 'b');
			return (ft_minisort_b(all, size - 1));
		}

		else
		{
			// push from b to a
			

		}




	}
	if (a < b)
	{
		if (b < c)
		{
			if (c < d)
			{
				
			}

		}
		


	}
	if (a < c && a < d && b < c && b < d)
	{
		ft_wr_rotate(all, 'b');
		ft_wr_rotate(all, 'b');
	}
	return (1);
}
*/
	// this one we could improve a bit, by using the Push back to A
	// as a tool for sorting...
int		ft_minisort_b(t_sorting *all, int size)
{
	int		ret1;		// for TESTING may be TMP
//	printf("--- In Minisort B\n");
	if (size == 1)
	{
		if (all->stack_a->index > all->stack_a->next->index)
		{
			ret1 = ft_wr_swap(all, 'a');
			if (ret1 != 1)
				printf("Minisort B Swap 1 ret1: %d\n", ret1);
		}
		ret1 = ft_wr_push(all, 'b');
		if (ret1 != 1)
			printf("minisort b push 1 ret1: %d\n", ret1);
	}
/*	else if (size == 4)
	{
		return (ft_b_quad_sort(all, size));
	}*/
	else
	{
		if (all->stack_b->index < all->stack_b->next->index)
		{
			if (all->stack_a->index > all->stack_a->next->index)
			{
				ret1 = ft_wr_swap(all, 'c');
				if (ret1 != 1)
					printf("Minisort B Swap 2 ret1: %d\n", ret1);
			}
			else
			{
				ret1 = ft_wr_swap(all, 'b');
				if (ret1 != 1)
					printf("Minisort B Swap 3 ret1: %d\n", ret1);
			}
		}
		ret1 = ft_wr_push(all, 'b');
		if (ret1 != 1)
			printf("Minisort B push 2 ret1: %d\n", ret1);
		return (ft_minisort_b(all, size - 1));
	}
	return (1);
}

int		ft_pascal_threesort(t_sorting *all, int id, int size)
{
//	int		a;
//	int		b;
//	int		c;
	t_nlist	*stack;

	if (!all || id != 0)
		return (0);
	stack = all->stack_a;
//			a = stack->index;
//			b = stack->index;
//			c = stack->index;
	if (size == 3)
	{
		while (!(stack->index < stack->next->index \
				&& stack->next->index < stack->next->next->index))
		{
			if (stack->next->index > stack->index \
				&& stack->next->index > stack->next->next->index)
				ft_wr_reverse_rotate(all, 'a');
			else if (stack->next->index < stack->index \
				&& stack->next->index > stack->next->next->index)
				ft_wr_rotate(all, 'a');
			else if (stack->next->index > stack->index \
				&& stack->next->index < stack->next->next->index)
				ft_wr_swap(all, 'a');
			else if (stack->next->index < stack->index \
				&& stack->index > stack->next->next->index)
				ft_wr_rotate(all, 'a');
			stack = all->stack_a;
		}
	}
	else if (size == 2 && stack->index > stack->next->index)
		ft_wr_swap(all, 'a');
	return (1);
}

	// i think it's secure...
	// may be a little excessive check again before push
int		ft_minisort(t_sorting *all, int id, int size)
{
	if (!all)
		return (0);
	if (id == 0)
	{
		// i think what Pascal does here is if size = size_of_a then you do
			// a threesort (because it was sent to minisort cuz it's small)
		// otherwise, if size != size_a you do minisort_a
		if (size != all->size_a && all->size_a < 4)
		{
//			if (!ft_sort_end_case(all, 'a'))
			if (!ft_pascal_threesort(all, 0, size))
				return (0);
		}
		else 
		{
			if (!ft_minisort_a(all, size))
				return (0);
		}
	}
	else if (id == 1)
	{
		if (!ft_minisort_b(all, size))
			return (0);
	}
	else
		return (0);
	return (1);
}





