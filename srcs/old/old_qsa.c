/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_qsa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 19:20:05 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// ALL of this is OBSOLETE
#include "push_swap.h"


// lets use this for now for testing purposes...
	// will absolutely make it better
	// may need to expand this to be able to handle 2,3,4 or maybe even more
	// small size lists of numbers
int		ft_sort_end_cases(t_sorting *all, t_list **stack, char id)
{
	int		a;
	int		b;
	int		c;

//	printf("in the end cases sort\n");
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


