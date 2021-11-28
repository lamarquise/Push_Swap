/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 18:09:39 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This is Secure! enough...

int	main_p3(t_sorting *all, int **int_tab)
{
	if (!ft_start_push_swap(all, all->size_total))
	{
		ft_free_nlist_elems(&all->stack_a);
		ft_free_nlist_elems(&all->stack_b);
		ft_free_int_tab(int_tab);
		ft_ilstdel_all(&all->op_list);
		return (0);
	}
	ft_post_processing(all);
	ft_print_op_codes(all->op_list);
	return (1);
}

int	main_p2(t_sorting *all, int **int_tab)
{
	if (!ft_create_stack(&all->stack_a, int_tab, all->size_total))
	{
		ft_free_nlist_elems(&all->stack_a);
		ft_free_int_tab(int_tab);
		return (0);
	}
	all->size_a = all->size_total;
	all->size_b = 0;
	all->size_op = 0;
	if (!ft_sort_by_index(all))
	{
		ft_free_nlist_elems(&all->stack_a);
		ft_free_int_tab(int_tab);
		return (0);
	}
	if (!main_p3(all, int_tab))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int				*int_tab;
	t_sorting		all;

	if (ac < 2)
		return (0);
	all.stack_a = NULL;
	all.stack_b = NULL;
	int_tab = NULL;
	all.op_list = NULL;
	all.size_total = ft_parser(&av[1], &int_tab, ac - 1);
	if (all.size_total < 1)
	{
		ft_free_int_tab(&int_tab);
		if (all.size_total == -1)
			return (0);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!main_p2(&all, &int_tab))
		return (ft_error_msg_fd("Error\n", 2, 0));
	ft_free_nlist_elems(&all.stack_a);
	ft_free_nlist_elems(&all.stack_b);
	ft_free_int_tab(&int_tab);
	ft_ilstdel_all(&all.op_list);
	return (0);
}
