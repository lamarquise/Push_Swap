/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_auxilary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/03 22:31:22 by ericlazo         ###   ########.fr       */
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
//	total = total / size;
		// do i need the -1 ?
//	printf("end of get_mean, total: %ld\n", total);
//	return ((min + max) / 2);
	return ((int)(total / size));
}


// lets use this for now for testing purposes...
	// will absolutely make it better
	// may need to expand this to be able to handle 2,3,4 or maybe even more
	// small size lists of numbers
int		ft_sort_end_cases(t_sorting *all, t_list **stack, char id)
{
	int		a;
	int		b;
	int		c;

	printf("in the end cases sort\n");
	ft_print_both_stacks(all);
	if (!all || !stack)	// and !*stack?
		return (0);

	a = *((int*)(*stack)->content);
	b = *((int*)(*stack)->next->content);
	c = *((int*)(*stack)->next->next->content);
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

	return (1);
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









// NONE of this stuff is useful...



	// will almost certainly want to move this...
void	*ft_lstlast_pointer(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}

	// will almost certainly want to move this...
void	*ft_pointer_at_index(t_list *lst, int index)
{
	void	*ret;
	int		i;
	t_list *tmp;

	if (!lst || index < 0)
		return (NULL);
	ret = NULL;
	i = 0;
	tmp = lst;
	while (tmp->next && i < index - 1)
	{
		tmp = tmp->next;
		++i;
	}
		ret = tmp->content;
	return (ret);
}


/*
	// this function is super ugly but i expect it will work,
		// good enough for now...
	// different if 3 are in Stack A or B
	// for like 3, 2 or 1 size stack sections
int		ft_minisort(t_sorting *all, int id, int size)
{
	int		a;
	int		b;
	int		c;
	t_list	*stack;

	printf("minisort size: %d\n", size);
	if (id == 0)
		stack = all->stack_a;
	else if (id == 1)
		stack = all->stack_b;
	if (size < 2)
		return (1);	// if minisort called on Stack B should call push_all after
	else if (size == 2)
	{
		if (id == 0 && *((int*)stack->content) > *((int*)stack->next->content))
			ft_wr_swap(all, id + 'a');
		else if (id == 1 && *((int*)stack->content) < *((int*)stack->next->content))
			ft_wr_swap(all, id + 'b');
	}
	else if (size == 3)
	{
		a = *((int*)stack->content);
		b = *((int*)stack->next->content);
		c = *((int*)stack->next->next->content);

		if (a > b && a < c)	// #1
		{
			if (id == 0)
				ft_wr_swap(all, id);
			else if (id == 1)
				ft_wr_reverse_rotate(all, id);
		}
		else if (a > b && b > c)	// #2
		{
			if (id == 0)
			{
				ft_wr_swap(all, id + 'a');
				ft_wr_reverse_rotate(all, id + 'a');
			}
			else if (id == 1)	// excessively explicit
				return (1);
		}
		else if (a > c && c > b)	// #3
		{
			if (id == 0)
				ft_wr_rotate(all, id + 'a');
			else if (id == 1)
			{
				ft_wr_swap(all, id +'a');
				ft_wr_rotate(all, id + 'a');
			}
		}
		else if (a < c && c < b)	// #4
		{
			if (id == 0)
			{
				ft_wr_swap(all, id + 'a');
				ft_wr_rotate(all, id + 'a');
			}
			else if (id == 1)
				ft_wr_rotate(all, id + 'a');
		}
		else if (a > c && a < b)	// #5
		{
			if (id == 0)
				ft_wr_reverse_rotate(all, id + 'a');
			else if (id == 1)
				ft_wr_swap(all, id + 'a');
		}
		

	}

	return (1);		// diferent return?
}

*/



// Ok this actually needs so much work...
	// stolen directly from Pascal... 
	// i mean i could just send the Stack directly...
/*
//int		ft_get_mean(t_sorting *all, int id, int size)
int		ft_get_mean(t_list *stack, int size)
{
	int		min;
	int		max;

	min = INTMIN;
	max = INTMAX;

	while (size)
	{
		if (*((int*)stack->content) > min)
			min = *((int*)stack->content);
		if (*((int*)tmp_a->content) < max)
			max = *((int*)stack->content); 
		// might not be next????
		stack = stack->next;
		--size;
	}
		// idk why there's a -1...
	return ((min + max - 1) / 2);
}
*/


