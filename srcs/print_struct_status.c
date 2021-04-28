/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 03:47:49 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:13:51 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"


void	ft_print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putnbrnl(*((int*)(tmp->content)));
		tmp = tmp->next;
	}
}

void	ft_print_both_stacks(t_mysort *all)
{
	ft_putstr("Stack A:\n----------\n");
	ft_print_stack(all->stack_a);
	ft_putstr("Stack B:\n----------\n");
	ft_print_stack(all->stack_b);
}

void	ft_print_stack_info(t_stack_info *info)
{
	ft_printf("Max: %d, Min: %d, Mean: %d, Size: %d, Rot: %d\n", info->max, \
			info->min, info->size, info->rot);
}

void	ft_print_mysort_all(t_mysort *all)
{
	ft_printf("STATUS\n---------\nSize Total: %d\n", all->size_total);
	ft_putstr("\nStack A Info:\n---\n");
	ft_print_stack_info(all->info_a);
	ft_putstr("\nStack B Info:\n---\n");
	ft_print_stack_info(all->info_b);

	ft_putstr("\n\n");

	ft_print_both_stacks(all);
}