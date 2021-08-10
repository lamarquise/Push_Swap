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


void	ft_print_stack(t_nlist *stack)
{
	t_nlist	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putnbr(*((int*)(tmp->content)));
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

/*
void	ft_print_stack_info(t_stack_info *info)
{
	ft_printf("Max: %d, Min: %d, Mean: %d, Size: %d, Rot: %d\n", info->max, \
			info->min, info->size, info->rot);
}

void	ft_print_mysort_all(t_sorting *all)
{
	ft_printf("STATUS\n---------\nSize Total: %d\n", all->size_total);
	ft_putstr("\nStack A Info:\n---\n");
	ft_print_stack_info(all->info_a);
	ft_putstr("\nStack B Info:\n---\n");
	ft_print_stack_info(all->info_b);

	ft_putstr("\n\n");

	ft_print_both_stacks(all);
}
*/

// this could actually be worth putting in Libft if not already there...
// i actually already made one of these...
/*
void	ft_print_inttab(int *tab, int size)
{
	int		i;

	if (!tab)
		return;
	i = 0;
	while (i < size)
		ft_putnbr(tab[i++]);


}
*/
