/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:46:38 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/11 00:30:04 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// this has become redundant...
	// the idea is, when i push a bunch of stuff over to B, this is the function
	// that brings it all back.

	// so unpush from B back to a
int		ft_unpush(t_sorting *all, char id)
{
	if (!all)
		return (0);


	// may need to rething the naming of IDs
	if (id == 'b')
	{
		while (all->info_b->size > 0)
		{
			ft_wr_push(all, 'a');
		}
	}


	return (1);
}

int		ft_my_sort(t_sorting *all)
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
		ft_wr_swap(all, &all->stack_a, 'a');
		// PB A to B
		ft_wr_push(all, 'b');
		run = 1;
	}



	return ((run = 1 ? ft_my_sort(all) : 1));
		// or should it be RECURSIVE?
//	return (1);	// if it went well.
}
