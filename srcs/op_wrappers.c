/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:53:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:32:51 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




// functions that wrap the Op functions


			// ok so the plan is to use ID to determin if i'm working on stack A or B
			// for swap may not need ID...
			// may not even need a wrapper for SWAP...
int		ft_swap_wrapper(t_mysort *all, t_list **stack, char id)
{
	if (!all || !stack || !ft_swap(stack))
		return (0);

	// we have applied the op, now we update all


		// being overly explicit for now so more readable

	// the state of the stack hasn't actually changed tho so nothing to update in all...

	if (id == 'a')
	{
		return (1);		

	}
/*	else if (id == 'b')
	{



	}
*/

	return (1);
}

	// would it just be easier not to have a Wrapper func at all? just do it all in
	// the Op func?

			// ok so the plan is to use ID to determin if i'm working on stack A or B
		// may also not need ID for Push...
	// or we could do one for PA and 1 for PB...
int		ft_push_wrapper(t_mysort *all, char id)
{
	int		result;

	if (!all)
		return (0);

	// leave for now, but i hate it...
//	result = ft_push_to_from(stack_to, stack_from);
		// could put this in if above...
//	if (result != 1)
//		return (result);	// meaing will return 2 if nothing happend cuz empty stack
	// ideally, there will never be any ops performed on empty stacks cuz that's a waste
	// of an op needlessly
	// but for the sake of refining my algorithm we will keep this for now...
		


		// being overly explicit for now so more readable

	// PA is B->A so stack_to is A and stack_from is B

	if (id == 'a')
	{
		// might need to be &(...)
		result = ft_push_to_from(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);

		++all->info_a->size;
		--all->info_b->size;
		if (*((int*)all->stack_a->content) > all->info_a->max)
			all->info_a->max = *((int*)all->stack_a->content);
		if (*((int*)all->stack_a->content) < all->info_a->min)
			all->info_a->min = *((int*)all->stack_a->content);

		// recalculate the Mean?

	}
	else if (id == 'b')		// PB A to B
	{
		result = ft_push_to_from(&all->stack_a, &all->stack_a);
		if (result != 1)
			return (result);

		++all->info_b->size;
		--all->info_a->size;
		if (*((int*)all->stack_b->content) > all->info_b->max)
			all->info_b->max = *((int*)all->stack_b->content);
		if (*((int*)all->stack_b->content) < all->info_b->min)
			all->info_b->min = *((int*)all->stack_b->content);

	}

	return (1);
}


int		ft_ratate_wrapper(t_mysort *all, char id)
{
	int		result;

	if (!all)
		return (0);

		// RA rotate A, First becomes Last
	if (id == 'a')
	{
		result = ft_rotate(&all->stack_a);
		if (result != 1)
			return (result);

		++all->info_a->rot;

	}
	else if (id == 'b')
	{
		result = ft_rotate(&all->stack_b);
		if (result != 1)
			return (result);

		++all->info_b->rot;
	}
	// could add c where c is rotate both...


	return (1);
}

int		ft_reverse_rotate_wrapper(t_mysort *all, char id)
{
	int		result;

	if (!all)
		return (0);

		// RRA reverse rotate A, Last becomes First
	if (id == 'a')
	{
		result = ft_reverse_rotate(&all->stack_a);
		if (result != 1)
			return (result);

		--all->info_a->rot;

	}
	else if (id == 'b')
	{
		result = ft_reverse_rotate(&all->stack_b);
		if (result != 1)
			return (result);

		--all->info_b->rot;
	}
	// could add c where c is rotate both...


	return (1);
}




