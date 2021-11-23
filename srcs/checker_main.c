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


	// the function that actually checks if all the Nums are in order...
	// The 1st elem is now the TOP of the List and the Last elem is the Bottom.

	// OMG need to check if B is empty!!!!!!!!

	// This shit needs to use "is_sorted.."
//int		ft_checker(t_nlist *stack_a, t_nlist *stack_b)
int		ft_checker(t_sorting *all)
{
	int		prev;
	t_nlist	*tmp;

	if (!all->stack_a || all->stack_b)
		return (0);
	tmp = all->stack_a;
		// super ulgy but we want to grab the void* and have it be an int* 
		// and dereference that int* into an int, with the * at the front...
	// May need to add some () somewhere... IDK
	prev = *((int*)tmp->content);
	tmp = tmp->next;

		// if there is only 1 elem in the list, no loop, and order is Good?
		// check sujet...
	while (tmp)
	{
//		printf("prev: %d\n", prev);
		if (*((int*)tmp->content) <= prev)
			return (0);
		prev = *((int*)tmp->content);
		tmp = tmp->next;
	}
//	ft_print_both_stacks(all);
	return (1);
}

int		main(int ac, char **av)
{
	t_list		*op_codes;
	int			*int_tab;
	t_sorting 	all;
	// So i am going to create a t_sorting all but just not fill out 
	// the stack info part, seems fine?

	if (ac < 2)
		return (0);
	all.stack_a = NULL;
	all.stack_b = NULL;
	all.op_list = NULL;
	op_codes = NULL;
	int_tab = NULL;

	all.size_total = ft_parser(&av[1], &int_tab, ac - 1);
	if (all.size_total < 1)
	{
		ft_free_int_tab(&int_tab);
		if (all.size_total == -1)
			return (0);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_parse_op_codes(&op_codes))
	{
		// Parse op codes is where i check if anything in STDIN vs STDERR
		ft_free_list_of_str(&op_codes);
		ft_free_int_tab(&int_tab);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_create_stack(&all.stack_a, &int_tab, all.size_total))
	{
		ft_free_list_of_str(&op_codes);
		ft_free_nlist_elems(&all.stack_a);
		ft_free_int_tab(&int_tab);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_apply_ops(&all, &op_codes))
	{
		ft_free_list_of_str(&op_codes);
		ft_free_nlist_elems(&all.stack_a);
		ft_free_nlist_elems(&all.stack_b);
		ft_free_int_tab(&int_tab);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}
	if (!ft_checker(&all))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");

// hold up, is there an oplist to free?
	ft_free_list_of_str(&op_codes);
	ft_free_nlist_elems(&all.stack_a);
	ft_free_nlist_elems(&all.stack_b);
	ft_free_int_tab(&int_tab);
//	ft_ilstdel_all(&all.op_list); // I'm not convinced i use all.op_list
	return (0);
}
