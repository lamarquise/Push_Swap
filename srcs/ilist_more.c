/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilist_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:49:50 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/24 21:21:43 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Is Secure!
	// no leaks but other checks never get used upstream...

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

int	ft_print_op_codes_p2(t_ilist *op_code)
{
	if (!op_code)
		return (1);
	if (op_code->num == 4)
		write(1, "pb\n", 3);
	else if (op_code->num == 5)
		write(1, "sb\n", 3);
	else if (op_code->num == 6)
		write(1, "rb\n", 3);
	else if (op_code->num == 7)
		write(1, "rrb\n", 4);
	else if (op_code->num == 8)
		write(1, "ss\n", 3);
	else if (op_code->num == 9)
		write(1, "rr\n", 3);
	else if (op_code->num == 10)
		write(1, "rrr\n", 4);
	else
		return (0);
	return (1);
}

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
		else if (!ft_print_op_codes_p2(tmp))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_remove_next_two(t_sorting *all, t_ilist **cur)
{
	t_ilist	*tmp;

	if (!all || !cur)
		return (0);
	if ((*cur)->next->next->next)
		tmp = (*cur)->next->next->next;
	else
		tmp = NULL;
	free((*cur)->next);
	free((*cur)->next->next);
	(*cur)->next = tmp;
	all->size_op -= 2;
	return (1);
}

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
	return (1);
}
