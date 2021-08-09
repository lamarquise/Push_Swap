/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:49:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 21:06:07 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


	// in theory, once the Linked list representing the Stack has been 
	// Allocated
// we should never have to reallocate elements again... they just get moved
	// around, and then we free them at the end
	// Opperating under this assumption for now...



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
	t_nlist		*stack_a;
	t_nlist		*stack_b;
	t_list		*op_codes;
	int			*int_tab;

	t_sorting 	all;
	// So i am going to create a t_sorting all but just not fill out 
	// the stack info part, seems fine?

//	printf("|-------Checker Start--------|\n");
		// Should 0 be the return in case of Error?
	if (ac < 2)
		return (ft_error_msg("ERROR: No list of ints\n", 0));


	stack_a = NULL;
	stack_b = NULL;
	op_codes = NULL;
	int_tab = NULL;



	if (!(all.size_total = ft_parser(&av[1], &int_tab, ac - 1)))
		return (ft_error_msg("ERROR: Bad List\n", 0));

//	ft_print_inttab(int_tab, all.size_total);
	if (!ft_parse_op_codes(&op_codes))
		return (ft_error_msg("ERROR: Bad OP Codes\n", 0));


	if (!ft_create_stack(&stack_a, &int_tab, all.size_total))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}

	all.stack_a = stack_a;
	all.stack_b = stack_b;


//	ft_print_both_stacks(&all);

	if (!ft_apply_ops(&all, &op_codes))
		return (ft_error_msg("ERROR: Failed to apply sorting operations.\n", 0));



// This is where I do the Checking part...

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

	// maybe put the visuallizer and other bonuses here?


/*
** Freeing things prolly gonna move this
*/

	// We need to free
		// Op Codes list
		// Stack A (and B ?)
		// int_tab


	// make sure you free tab properly, not sure if i can just free tab or need to
	// free each index?

		// hummm this seems to freak it out...
//	free(tab);	// do i need more ?

//	printf("|-------Checker End--------|\n");

	return (0);
}





