/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 03:47:49 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:28:04 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// Is Secure

void	ft_print_stack(t_nlist *stack)
{
	t_nlist	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (!tmp->content)
			return ;
		ft_putnbr(*((int *)(tmp->content)));
		write(1, "  --  index: ", 13);
		ft_putnbrnl(tmp->index);
		tmp = tmp->next;
	}
}

void	ft_print_both_stacks(t_sorting *all)
{
	ft_putstr("Stack A:\n----------\n");
	ft_print_stack(all->stack_a);
	ft_putstr("Stack B:\n----------\n");
	ft_print_stack(all->stack_b);
}
