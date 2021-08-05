/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/05 21:11:10 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// could put some free shit up here
	// but may need to have some of the free funcs in utils so
	// can be used by both!
int		ft_is_reverse_sorted(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
			// i think this is good enough
		if (*((int*)tmp->content) < *((int*)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}

	return (1);
}

int		ft_rev_sort(t_sorting *all, int size)
{
	// swap and push to b
	// then push all back
	while (size > 3)
	{
		ft_wr_reverse_rotate(all, 'a');
		ft_wr_push(all, 'b');
	}
	ft_minisort(all, 'a', 3);
	ft_all_push_to_from(all, 'a');
	return (1);
}

int		main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
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


	// here i would like to run some tests to make sure the list is all
	// good, like numbers and shit...
	// no duplicates


	if (!ft_create_stack(&stack_a, &int_tab, all.size_total))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}

	all.stack_a = stack_a;
	all.stack_b = stack_b;
	all.size_a = all.size_total;
	all.size_b = 0;


	ft_start_push_swap(&all, all.size_total);

//	ft_print_both_stacks(&all);

	// figure out how to free int_tab...

	ft_lstclear(&stack_a, &ft_free_int);

//	printf("|-------Push Swap End-------|\n");

	return (0);
}
