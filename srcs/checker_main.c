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

	if (!all->stack_a || all->stack_b)
		return (0);

		// super ulgy but we want to grab the void* and have it be an int* 
		// and dereference that int* into an int, with the * at the front...
	// May need to add some () somewhere... IDK
	prev = *((int*)all->stack_a->content);
	all->stack_a = all->stack_a->next;

		// if there is only 1 elem in the list, no loop, and order is Good?
		// check sujet...
	while (all->stack_a)
	{
//		printf("prev: %d\n", prev);
		if (*((int*)all->stack_a->content) <= prev)
			return (0);
		prev = *((int*)all->stack_a->content);
		all->stack_a = all->stack_a->next;
	}
//	ft_print_both_stacks(all);
	return (1);
}






	// desparately needs to be Secured!!!!!

int		main(int ac, char **av)
{
	t_list		*op_codes;		// i could put op_codes in op_list in all..
				// DO that if you feel you have time...
	int			*int_tab;

	t_sorting 	all;
	// So i am going to create a t_sorting all but just not fill out 
	// the stack info part, seems fine?

//	printf("|-------Checker Start--------|\n");
		// Should 0 be the return in case of Error?
	if (ac < 2)
		return (ft_error_msg_fd("Error\n", 2, 0));


	all.stack_a = NULL;
	all.stack_b = NULL;
	all.op_list = NULL;
	op_codes = NULL;
	int_tab = NULL;



	if (!(all.size_total = ft_parser(&av[1], &int_tab, ac - 1)))
		return (ft_error_msg_fd("Error\n", 2, 0));

//	ft_print_inttab(int_tab, all.size_total);
	if (!ft_parse_op_codes(&op_codes))
	{
		ft_free_list_of_str(&op_codes);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}

	if (!ft_create_stack(&all.stack_a, &int_tab, all.size_total))
	{
		ft_free_list_of_str(&op_codes);
		ft_free_nlist_elems(&all.stack_a);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}



//	ft_print_both_stacks(&all);

	if (!ft_apply_ops(&all, &op_codes))
	{
		ft_free_list_of_str(&op_codes);
		ft_free_nlist_elems(&all.stack_a);
		ft_free_nlist_elems(&all.stack_b);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg_fd("Error\n", 2, 0));
	}




	// Don't use this cuz Info never get's inited here...
//	ft_print_mysort_all(&all);

//	ft_print_both_stacks(&all);
	if (!ft_checker(&all))
	{
		ft_putstr("KO\n");
	}
	else
	{
		ft_putstr("OK\n");
	}


/*
** Freeing things prolly gonna move this
*/
	ft_free_list_of_str(&op_codes);
	ft_free_nlist_elems(&all.stack_a);
	ft_free_nlist_elems(&all.stack_b);
	ft_free_int_tab(&int_tab, all.size_total);

	// We need to free
		// Op Codes list
		// Stack A (and B ?)
		// int_tab


	return (0);
}





