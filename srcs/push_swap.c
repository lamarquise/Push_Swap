/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/27 01:29:36 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





int		main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	if (ac < 2)
		return (ft_error_msg("ERROR: no list of ints\n", 0));


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


// so far this is all identical to checker.c


	// this is where we would do the sorting


	// then we print the Operations in order to



	// this is also like checker.c

	ft_lstclear(&stack_a, &ft_free_int);


	return (0);
}
