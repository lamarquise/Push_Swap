/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_auxilary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/02 14:03:46 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// may need another file for these auxilary functions


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

// My own get_mean
	// Ok so this one gets me the mean Value of a subset of a Stack
	// we want size so we know where to stop
	// this assumes we are always starting at the top
int		ft_get_mean(t_sorting *all, int id, int size)
{
	int		min;
	int		max;
	t_list	*stack;

	min = INTMAX;
	max = INTMIN;
	if (id == 0)
		stack = all->stack_a;
	else if (id == 1)
		stack = all->stack_b;

	while (size)
	{
		if (*((int*)stack->content) < min)
			min = *((int*)stack->content);
		if (*((int*)tmp_a->content) > max)
			max = *((int*)stack->content); 
		// might not be next????
		stack = stack->next;
		--size;
	}
		// do i need the -1 ?
	return ((min + max) / 2);
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
	// what if insead of ID we sent the stack directly?
int		ft_sort_end_cases(t_sorting *all, char id)
{

	if (!all)
		return (0);

	if (id == 'a')
	{
		

	}
	else if (id == 'b')
	{


	}

	return (1);
}
*/
/*
	// may need to expand this to be able to handle 2,3,4 or maybe even more
	// small size lists of numbers
int		ft_sort_end_cases(t_sorting *all, t_list **stack, char id)
{
	int		a;
	int		b;
	int		c;

	printf("in the end cases sort\n");
	if (!all || !stack)	// and !*stack?
		return (0);

	a = *((int*)(*stack)->content);
	b = *((int*)(*stack)->next->content);
	c = *((int*)(*stack)->next->next->content);
	if (a > b && a < c)
	{
		ft_wr_swap(all, stack, id);
	}
	else if (a > b && b > c)
	{
		ft_wr_swap(all, stack, id);
		ft_wr_reverse_rotate(all, id);
	}
	else if (a > b && b < c)
	{
		ft_wr_rotate(all, id);
	} 
	else if (a < b && a < c)
	{
		ft_wr_swap(all, stack, id);
		ft_wr_rotate(all, id);
	}
	else if (a < b && a > c)
	{
		ft_wr_reverse_rotate(all, id);
	}

	return (1);
}
*/

int		ft_minisort()
{


	return (1);		// diferent return?
}






