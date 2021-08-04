/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_auxilary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 19:39:47 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// My own get_mean
	// Ok so this one gets me the mean Value of a subset of a Stack
	// we want size so we know where to stop
	// this assumes we are always starting at the top
int		ft_get_mean(t_sorting *all, int id, int size)
{
	int		c;
	int		min;
	int		max;
	long	total;
	t_list	*stack;

//	printf("--- Now in Get Mean --- size = %d, id = %d\n", size, id);
	c = 0;
	total = 0;
	min = INTMAX;
	max = INTMIN;
	if (id == 0)
		stack = all->stack_a;
	else if (id == 1)
		stack = all->stack_b;

	while (c < size)
	{
		if (*((int*)stack->content) < min)
			min = *((int*)stack->content);
		if (*((int*)stack->content) > max)
			max = *((int*)stack->content); 
		// might not be next????
		total += *((int*)stack->content);
//		printf("size: %d, min: %d, max: %d, total: %ld\n", size, min, max, total);
		stack = stack->next;
		++c;
		//--size;
	}
//	printf("end of get_mean, total: %ld\n", total);
	return ((int)(total / size));
}


	// Threesort is for when the stack is Empty except 3 values
	// ok i just used the End cases i found from that other guy,
		// seems to be working !?
int		ft_sort_end_case(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;
	char	id;

	id = 'a';
	if (size == 3)
	{
		a = *((int*)all->stack_a->content);
		b = *((int*)all->stack_a->next->content);
		c = *((int*)all->stack_a->next->next->content);
	/*	while (!(a < b && b < c))
		{




		}
	*/
		if (a > b && a < c)
		{
			ft_wr_swap(all, id);
		}
		else if (a > b && b > c)
		{
			ft_wr_swap(all, id);
			ft_wr_reverse_rotate(all, id);
		}
		else if (a > b && b < c)
		{
				ft_wr_rotate(all, id);
		} 
		else if (a < b && a < c)
		{
			ft_wr_swap(all, id);
			ft_wr_rotate(all, id);
		}
		else if (a < b && a > c)
		{
			ft_wr_reverse_rotate(all, id);
		}
	}
	return (1);
}



	// The Minisorts A and B are for sorting Partitions of size 3 or less
	// Stolen and Adapted Directly from Pascal, thanks
int		ft_minisort_a(t_sorting *all, int size)
{
	int		a;
	int		b;
	int		c;

//	printf("--- In Minisort A\n");
	if (size == 2 && *((int*)all->stack_a->content) \
		> *((int*)all->stack_a->next->content))
		ft_wr_swap(all, 'a');
	else if (size == 3)
	{
		a = *((int*)all->stack_a->content);
		b = *((int*)all->stack_a->next->content);
		c = *((int*)all->stack_a->next->next->content);
		if (a < b && b < c)
			return (1);
		else if (a > b)
		{
			if (*((int*)all->stack_b->content) \
				< *((int*)all->stack_b->next->content))
				ft_wr_swap(all, 'c');
			else
				ft_wr_swap(all, 'a');
		}
		else
		{
			ft_wr_rotate(all, 'a');
			ft_minisort_a(all, size - 1);
			ft_wr_reverse_rotate(all, 'a');
		}
		return (ft_minisort_a(all, size));
	}
	return (1);
}

	// this one we could improve a bit, by using the Push back to A
	// as a tool for sorting...
int		ft_minisort_b(t_sorting *all, int size)
{
//	printf("--- In Minisort B\n");
	if (size == 1)
	{
		if (*((int*)all->stack_a->content) > *((int*)all->stack_a->next->content))
			ft_wr_swap(all, 'a');
		ft_wr_push(all, 'b');
	}
	else
	{
		if (*((int*)all->stack_b->content) < *((int*)all->stack_b->next->content))
		{
			if (*((int*)all->stack_a->content) > *((int*)all->stack_a->next->content))
				ft_wr_swap(all, 'c');
			else
				ft_wr_swap(all, 'b');
		}
		ft_wr_push(all, 'b');
		return (ft_minisort_b(all, size - 1));
	}
	return (1);
}

int		ft_minisort(t_sorting *all, int id, int size)
{
	if (id == 0)
	{
		// i think what Pascal does here is if size = size_of_a then you do
			// a threesort (because it was sent to minisort cuz it's small)
		// otherwise, if size != size_a you do minisort_a
		if (size != all->info_a->size && all->info_a->size < 4)
			ft_sort_end_case(all, 'a');
		ft_minisort_a(all, size);

	}
	else if (id == 1)
	{
		ft_minisort_b(all, size);
	}

	return (1);
}







