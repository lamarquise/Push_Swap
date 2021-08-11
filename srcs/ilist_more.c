/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilist_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:49:50 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/11 22:58:16 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// not in Minilib for now
#include "push_swap.h"


// remove node 
// replace node
// combine nodes...


int	ft_print_ilist(t_ilist *lst)
{
	t_ilist	*tmp;

	if (!lst)
		return (1);
	tmp = lst;
	while (tmp)
	{
		ft_putnbrnl(tmp->num);
		tmp = tmp->next;
	}
	return (1);
}

	// may move...
	// ugly but should work...
int	ft_print_op_codes(t_ilist *op_codes)
{
	t_ilist	*tmp;

	if (!op_codes)
		return (1);
	tmp = op_codes;
	while (tmp)
	{
		if (tmp->num == 0)
			write(1, "pa\n", 3);
		else if (tmp->num == 1)
			write(1, "sa\n", 3);
		else if (tmp->num == 2)
			write(1, "ra\n", 3);
		else if (tmp->num == 3)
			write(1, "rra\n", 4);
		else if (tmp->num == 4)
			write(1, "pb\n", 3);
		else if (tmp->num == 5)
			write(1, "sb\n", 3);
		else if (tmp->num == 6)
			write(1, "rb\n", 3);
		else if (tmp->num == 7)
			write(1, "rrb\n", 4);
		else if (tmp->num == 8)
			write(1, "ss\n", 3);
		else if (tmp->num == 9)
			write(1, "rr\n", 3);
		else if (tmp->num == 10)
			write(1, "rrr\n", 4);
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


// need some funcs that remove nodes and such 


	// we send it 1 of 4
	// should be fine but IDK may need to secure...
int	ft_remove_next_two(t_sorting *all, t_ilist **cur)
{
	t_ilist	*tmp;

	if (!all || !cur)
		return (0);
	tmp = (*cur)->next->next->next;
	free((*cur)->next);
	free((*cur)->next->next);
	(*cur)->next = tmp;
	all->size_op -= 2;

	printf("removed 2\n");
	return (1);
}

	// we send it 1 of 2
	// should be fine but IDK may need to secure...
int	ft_replace_next_two_with_one(t_sorting *all, t_ilist **cur, int rep)
{
	t_ilist	*tmp;

	if (!all || !cur)
		return (0);
	tmp = (*cur)->next->next;
	free((*cur)->next);
	(*cur)->num = rep;
	(*cur)->next = tmp;
	--all->size_op;

	printf("replaced 2 with 1\n");

	return (1);
}









