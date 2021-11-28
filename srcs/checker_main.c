/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:49:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 11:57:23 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Is Secure!

int	ft_checker(t_sorting *all)
{
	int		prev;
	t_nlist	*tmp;

	if (!all->stack_a || all->stack_b)
		return (0);
	tmp = all->stack_a;
	prev = *((int *)tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (*((int *)tmp->content) <= prev)
			return (0);
		prev = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (1);
}

int	main_pc2(t_sorting *all, int **int_tab, t_list **op_codes)
{
	if (!all || !int_tab || !op_codes)
		return (0);
	all->stack_a = NULL;
	all->stack_b = NULL;
	if (!ft_create_stack(&all->stack_a, int_tab, all->size_total))
	{
		ft_free_list_of_str(op_codes);
		ft_free_nlist_elems(&all->stack_a);
		ft_free_int_tab(int_tab);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_apply_ops(all, op_codes))
	{
		ft_free_list_of_str(op_codes);
		ft_free_nlist_elems(&all->stack_a);
		ft_free_nlist_elems(&all->stack_b);
		ft_free_int_tab(int_tab);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_checker(all))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

int	main_op(t_list **op_codes)
{
	int	ret;

	if (!op_codes)
		return (0);
	*op_codes = NULL;
	ret = ft_parse_op_codes(op_codes);
	if (ret != 1)
	{
		ft_free_list_of_str(op_codes);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	return (1);
}

int	main(int ac, char **av)
{
	int			*int_tab;
	t_list		*op_codes;
	t_sorting	all;

	if (ac < 2)
		return (0);
	int_tab = NULL;
	if (!main_op(&op_codes))
		return (0);
	all.size_total = ft_parser(&av[1], &int_tab, ac - 1);
	if (all.size_total < 1)
	{
		ft_free_int_tab(&int_tab);
		ft_free_list_of_str(&op_codes);
//		if (all.size_total == -1)
//			return (0);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!main_pc2(&all, &int_tab, &op_codes))
		return (0);
	ft_free_list_of_str(&op_codes);
	ft_free_nlist_elems(&all.stack_a);
	ft_free_nlist_elems(&all.stack_b);
	ft_free_int_tab(&int_tab);
	return (0);
}
