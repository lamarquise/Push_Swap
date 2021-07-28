/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/25 19:32:55 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*int_tab;

	t_sorting		all;	// no need to free but should free 
							// things in it (if pointers)

	t_stack_info	info_a;
	t_stack_info	info_b;

//	printf("|-------Push Swap Start-------|\n");
	if (ac < 2)
		return (ft_error_msg("ERROR: no list of ints\n", 0));

	stack_a = NULL;
	stack_b = NULL;
	int_tab = NULL;

	if (!(all.size_total = ft_parser(av, &int_tab)))
		return (ft_error_msg("ERROR: Bad List\n", 0));


	if (!ft_create_stack(&stack_a, &int_tab, all.size_total))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}

//	printf("in main size_total: %d\n", all.size_total);
//	ft_print_inttab(int_tab, all.size_total);
//	printf("first elem of int_tab: %d\n", (int)*int_tab); 
//	printf("in main, after create stack int tab pointer val: %p\n", int_tab);


// so far this is all identical to checker.c

//	printf("push main test 1\n");

	// this is where we would do the sorting
		// first i need to init the Structure...


	if (!ft_init_stack_info(&info_a, all.size_total) || !ft_init_stack_info(&info_b, 0))
		return (ft_error_msg("ERROR: Failed to init stack_infos\n", 0));

	all.info_a = &info_a;
	all.info_b = &info_b;
	all.stack_a = stack_a;
	all.stack_b = stack_b;

	// we setup stack info for Stack A
	if (!ft_prep_stack_info(&info_a, int_tab) || !ft_prep_stack_info(&info_b, int_tab))
		return (ft_error_msg("ERROR: Failed to prep mysort_info\n", 0));

//	ft_printf("Pre Sorting\n");
//	ft_print_both_stacks(&all);
//	ft_print_mysort_all(&all);


//	printf("push main test 2\n");

//	if(!ft_mysort(&all))
//		return (ft_error_msg("ERROR: MySort failed to sort.\n", 0));

	if (!ft_bubble_sort(&all))
		return (ft_error_msg("ERROR: Bubble Sort failed to sort.\n", 0));

	// then we print the Operations in order to


//	printf("push main test 3\n");

	// now we print status...
//	ft_printf("\nPost Sort:\n");
//	ft_print_both_stacks(&all);
//	ft_print_mysort_all(&all);


	// this is also like checker.c

	ft_lstclear(&stack_a, &ft_free_int);

//	printf("|-------Push Swap End-------|\n");

	return (0);
}
