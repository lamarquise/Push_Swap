/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:46:38 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:32:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


	// the idea is, when i push a bunch of stuff over to B, this is the function
	// that brings it all back.

	// so unpush from B back to a
int		ft_unpush(t_mysort *all, char id)
{
	if (!all)
		return (0);


	// may need to rething the naming of IDs
	if (id == 'b')
	{
		while (all->info_b->size > 0)
		{
			ft_push_wrapper(all, 'a');
		}
	}


	return (1);
}

int		ft_mysort(t_mysort *all)
{
	int		run;	// if run = 1 we run again, recursively, else, we stop

	run = 0;

	if (!all)
		return (1);

	// this is the part where we call the op_wrapper funcs in a very specific order

	if (all->stack_a->next == NULL)
	{
		ft_unpush(all, 'b');
		run = 0;
	}


	if (*((int*)all->stack_a->content) > *((int*)all->stack_a->next->content))
	{
//		printf("test1\n");
		ft_swap_wrapper(all, &all->stack_a, 'a');
		// PB A to B
		ft_push_wrapper(all, 'b');
		run = 1;
	}



	return ((run = 1 ? ft_mysort(all) : 1));
		// or should it be RECURSIVE?
//	return (1);	// if it went well.
}
