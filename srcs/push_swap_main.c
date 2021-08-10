/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:45:00 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_nlist			*stack_a;
	t_nlist			*stack_b;
	int				*int_tab;

	t_sorting		all;	// no need to free but should free 
							// things in it (if pointers)

	// more secure
	if (ac < 2)
		return (ft_error_msg("ERROR: no list of ints\n", 0));

	stack_a = NULL;
	stack_b = NULL;
	int_tab = NULL;

		// need to free stuff?
					// could i direct send &av[1]
	if (!(all.size_total = ft_parser(&av[1], &int_tab, ac - 1)))
		return (ft_error_msg("ERROR: Bad List\n", 0));
	// No need to free int tab if fails cuz would not have been alocated..

//	ft_print_inttab(int_tab, all.size_total);

	// here i would like to run some tests to make sure the list is all
	// good, like numbers and shit...
	// no duplicates


	if (!ft_create_stack(&stack_a, &int_tab, all.size_total))
	{
		// i need a free stack that doesn't crash if there is no
			// stack...
		// also free int_tab
		ft_free_nlist_elems(&stack_a);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}

	all.stack_a = stack_a;
	all.stack_b = stack_b;
	all.size_a = all.size_total;
	all.size_b = 0;

//	ft_print_both_stacks(&all);

	if (!ft_sort_by_index(&all))
	{
		ft_free_nlist_elems(&stack_a);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg("ERROR: failed to pre sort\n", 0));
	}
	if (!ft_start_push_swap(&all, all.size_total))
	{
		ft_free_nlist_elems(&stack_a);
		ft_free_nlist_elems(&stack_b);
		ft_free_int_tab(&int_tab, all.size_total);
		return (ft_error_msg("ERROR: failed to Sort\n", 0));
	}

	ft_print_both_stacks(&all);

		// in theory if the stack is empty nothing happens...
	ft_free_nlist_elems(&stack_a);
	ft_free_nlist_elems(&stack_b);
	ft_free_int_tab(&int_tab, all.size_total);

//	ft_lstclear(&stack_a, &ft_free_int);
	ft_nlstdel_all(&stack_a);
//	ft_nlstdel_all(&stack_b);

	// this leads to Leaks
/*	stack_a = NULL;
	stack_b = NULL;
	all.stack_a = NULL;
	all.stack_b = NULL;
*/
	ft_print_both_stacks(&all);

//	printf("|-------Push Swap End-------|\n");
/*
	while (1)
	{

	}
*/

	return (0);
}
