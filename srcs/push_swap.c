/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:20:35 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*int_tab;		// may want a clearer name... like int_tab?
	int				size;		// also clearer name? a long? size_t?
	// could forgo size and use info.size_total from the start...
	t_mysort		all;	// no need to free but should free things in it (if pointers)

	t_stack_info	info_a;
	t_stack_info	info_b;

	if (ac < 2)
		return (ft_error_msg("ERROR: no list of ints\n", 0));

	stack_a = NULL;
	stack_b = NULL;
	int_tab = NULL;

		// could send tab... easier to free?
		// will this work? like en cas d'erreur we return 0
	if (!(size = ft_parser(av, &int_tab)))
		return (ft_error_msg("ERROR: Bad List\n", 0));

			// not sure if this skip will work... let's try it
	if (!ft_create_stack(&stack_a, &int_tab, size))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}


// so far this is all identical to checker.c



	// this is where we would do the sorting
		// first i need to init the Structure...


	if (!ft_init_stack_info(&info_a, size) || !ft_init_stack_info(&info_b, 0))
		return (ft_error_msg("ERROR: Failed to init stack_infos\n", 0));

	all.info_a = &info_a;
	all.info_b = &info_b;
	all.stack_a = stack_a;
	all.stack_b = stack_b;

	// we setup stack info for Stack A
	if (!ft_prep_stack_info(&info_a, int_tab))
		return (ft_error_msg("ERROR: Failed to prep mysort_info\n", 0));

	ft_printf("Pre Sorting\n");
	ft_print_both_stacks(&all);
//	ft_print_mysort_all(&all);



//	if (!ft_prep_mysort_info(&info_all, tab))
//		return (ft_error_msg("ERROR: Failed to prep mysort_info\n", 0));

		// now size_a size_total, min, max, mean are all useful values, and the rest
		// are also set.

		// do i need anything else? int_tab?
	if(!ft_mysort(&all))
		return (ft_error_msg("ERROR: MySort failed to sort.\n", 0));



	// then we print the Operations in order to



	// now we print status...
	ft_printf("\nPost Sort:\n");
	ft_print_both_stacks(&all);
//	ft_print_mysort_all(&all);


	// this is also like checker.c

	ft_lstclear(&stack_a, &ft_free_int);


	return (0);
}
