/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:49:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:11:57 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


	// in theory, once the Linked list representing the Stack has been Allocated
	// we should never have to reallocate elements again... they just get moved
	// around, and then we free them at the end
	// Opperating under this assumption for now...



	// the function that actually checks if all the Nums are in order...
	// The 1st elem is now the TOP of the List and the Last elem is the Bottom.

	// OMG need to check if B is empty!!!!!!!!

int		ft_checker(t_list *stack_a, t_list *stack_b)
{
	int		prev;

	if (!stack_a || stack_b)
		return (0);

		// super ulgy but we want to grab the void* and have it be an int* 
		// and dereference that int* into an int, with the * at the front...
	prev = *((int*)stack_a->content);
	stack_a = stack_a->next;

		// if there is only 1 elem in the list, no loop, and order is Good?
		// check sujet...
	while (stack_a)
	{
//		printf("prev: %d\n", prev);
		if (*((int*)stack_a->content) <= prev)
			return (0);
		prev = *((int*)stack_a->content);
		stack_a = stack_a->next;
	}
	return (1);
}

int		main(int ac, char **av)
{

		// Should 0 be the return in case of Error?
	if (ac < 2)
		return (ft_error_msg("ERROR: No list of ints\n", 0));

	// just testing
//	ft_print_strtab(av);

	// may move this to a separat func later

	t_list		*stack_a;
	t_list		*stack_b;

	int			*tab;		// may want a clearer name...
	int			size;		// also clearer name? a long? size_t?

	stack_a = NULL;
	stack_b = NULL;
	tab = NULL;

		// could send tab... easier to free?
		// will this work? like en cas d'erreur we return 0
	if (!(size = ft_parser(av, &tab)))
		return (ft_error_msg("ERROR: Bad List\n", 0));

			// not sure if this skip will work... let's try it
	if (!ft_create_stack(&stack_a, &tab, size))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}


/*
**	This is the part where i Apply the Operations in whatever order they were
**	given to me...
*/

	if (!ft_apply_ops(&stack_a, &stack_b))
		return (ft_error_msg("ERROR: Failed to apply sorting operations.\n", 0));



	// testing
//	ft_print_both_stacks(&all);

/*	int i;
	t_list	*tmp_a;
	t_list	*tmp_b;
	
	tmp_a = stack_a;
	tmp_b = stack_b;
	i = 0;
	ft_putstr("Stack A:\n------\n");
	while (tmp_a)
	{
	//	printf("an int: |%d|\n", (int)(*(int*)(tmp->content)));
		ft_putnbrnl(*((int*)(tmp_a->content)));
		tmp_a = tmp_a->next;
	}
	ft_putstr("Stack B:\n------\n");
	while (tmp_b)
	{
	//	printf("an int: |%d|\n", (int)(*(int*)(tmp->content)));
		ft_putnbrnl(*((int*)(tmp_b->content)));
		tmp_b = tmp_b->next;
	}
*/

// This is where I do the Checking part...

	if (!ft_checker(stack_a, stack_b))
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

	//using lstclear for now... kinda stupid cuz i can free the table but whateves...

		// seems to work, will test properly later...
	ft_lstclear(&stack_a, &ft_free_int);


	// make sure you free tab properly, not sure if i can just free tab or need to
	// free each index?

		// hummm this seems to freak it out...
//	free(tab);	// do i need more ?


	return (0);
}





