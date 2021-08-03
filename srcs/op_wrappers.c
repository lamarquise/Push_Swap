/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:53:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/03 19:36:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// functions that wrap the Op functions


			// ok so the plan is to use ID to determin if i'm working on stack A or B
			// for swap may not need ID...
			// may not even need a wrapper for SWAP...
int		ft_wr_swap(t_sorting *all, char id)
{
	if (!all)
		return (0);
	if (id == 'a')
		ft_op_swap(&all->stack_a);
	else if (id == 'b')
		ft_op_swap(&all->stack_b);
	else if (id == 'c')
		ft_op_swap_both(&all->stack_a, &all->stack_b);
	// we have applied the op, now we update all

	// the state of the stack hasn't actually changed tho so 
	// nothing to update in all...

	if (id == 'a')
	{
		write(1, "sa\n", 3);
		return (1);		// not sure if necessary to ret here
	}
	else if (id == 'b')
	{
		write(1, "sb\n", 3);
		return (1);
	}
	else if (id == 'c')		// i think this is how i wanna do this
	{
		write(1, "ss\n", 3);
		return (1);
	}

	return (1);
}

	// Had to switch the ifs, A and B make less sense, but work way should...
	// i hate everything...
int		ft_wr_push(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);
//	printf("Tip Top of Wr Push, id = |%c|\n", id);
	// PA is B->A so stack_to is A and stack_from is B

	if (id == 'b')
	{
//		printf("wr push we made it to top of id 'a'\n");
		// might need to be &(...)
		result = ft_op_push_to_from(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);

		++all->info_a->size;
		--all->info_b->size;
		if (*((int*)all->stack_a->content) > all->info_a->max)
			all->info_a->max = *((int*)all->stack_a->content);
		if (*((int*)all->stack_a->content) < all->info_a->min)
			all->info_a->min = *((int*)all->stack_a->content);

		write(1, "pa\n", 3);
		// recalculate the Mean?
		// we could recalculate the mean before we push, just sub 1
		// from size of list
		// we could also store total (like the value of all the #s added
		// together

	}
	else if (id == 'a')		// PB A to B
	{
//		printf("wr push we made it to top of id 'b'\n");
		result = ft_op_push_to_from(&all->stack_b, &all->stack_a);
		if (result != 1)
			return (result);

//		printf("wr push we made it to mid of id 'b'\n");
		++all->info_b->size;
		--all->info_a->size;
		if (all->stack_b != NULL)
		{
			if (*((int*)all->stack_b->content) > all->info_b->max)
				all->info_b->max = *((int*)all->stack_b->content);
			if (*((int*)all->stack_b->content) < all->info_b->min)
				all->info_b->min = *((int*)all->stack_b->content);
			write(1, "pb\n", 3);
		}
//		printf("wr push we made it to end of id 'b'\n");

	}

	return (1);
}

int     ft_all_push_to_from(t_sorting *all, char id)
{
	if (!all)   // maybe also check if ID is a valid char?
		return (0);
	if (id == 'a')
	{
		while (all->stack_b != NULL)        // for some reason if not != NULL
		{									// it segfaults
			if (!ft_wr_push(all, 'b'))
				return (0);
		}
	}
	else if (id == 'b')
	{
		while (all->stack_a != NULL)
		{
			if (!ft_wr_push(all, 'a'))
				return (0);
		}
	}
	else
		return (0);

	return (1);
}

int		ft_wr_rotate(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);

		// RA rotate A, First becomes Last
	if (id == 'a')
	{
		result = ft_op_rotate(&all->stack_a);
		if (result != 1)
			return (result);

		++all->info_a->rot;
		write(1, "ra\n", 3);

	}
	else if (id == 'b')
	{
		result = ft_op_rotate(&all->stack_b);
		if (result != 1)
			return (result);

		++all->info_b->rot;
		write(1, "rb\n", 3);
	}
	// could add c where c is rotate both...
	// yes need that for write rr

	return (1);
}

int		ft_wr_reverse_rotate(t_sorting *all, char id)
{
	int		result;

	if (!all)
		return (0);

		// RRA reverse rotate A, Last becomes First
	if (id == 'a')
	{
		result = ft_op_reverse_rotate(&all->stack_a);
		if (result != 1)
			return (result);

		--all->info_a->rot;
		write(1, "rra\n", 4);

	}
	else if (id == 'b')
	{
		result = ft_op_reverse_rotate(&all->stack_b);
		if (result != 1)
			return (result);

		--all->info_b->rot;
		write(1, "rrb\n", 4);
	}
	// could add c where c is rotate both...

	// need to add rrr somehow...
	return (1);
}




