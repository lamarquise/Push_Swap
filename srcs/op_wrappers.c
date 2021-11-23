/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_wrappers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:53:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:24:09 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Is Secure!

int		ft_wr_swap(t_sorting *all, char id)
{
	if (!all)
		return (0);
	if (id == 'a' && ft_op_swap(&all->stack_a))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(1)))
			return (0);
		++all->size_op;
		return (1);
	}
	else if (id == 'b' && ft_op_swap(&all->stack_b))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(5)))
			return (0);
		++all->size_op;
		return (1);
	}
	else if (id == 'c' && ft_op_swap_both(&all->stack_a, &all->stack_b))
	{
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(8)))
			return (0);
		++all->size_op;
		return (1);
	}
	return (0);
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

	if (id == 'b')		// PA is push B to A
	{
//		printf("wr push we made it to top of id 'a'\n");
		// might need to be &(...)
		result = ft_op_push_to_from(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(0)))
			return (0);
		++all->size_op;
		++all->size_a;
		--all->size_b;
//		write(1, "pa\n", 3);

/*		++all->info_a->size;
		--all->info_b->size;
		if (*((int*)all->stack_a->content) > all->info_a->max)
			all->info_a->max = *((int*)all->stack_a->content);
		if (*((int*)all->stack_a->content) < all->info_a->min)
			all->info_a->min = *((int*)all->stack_a->content);
*/
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
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(4)))
			return (0);
		++all->size_op;
		--all->size_a;
		++all->size_b;
//		write(1, "pb\n", 3);

//		printf("wr push we made it to mid of id 'b'\n");
//		++all->info_b->size;
//		--all->info_a->size;
/*		if (all->stack_b != NULL)
		{
			if (*((int*)all->stack_b->content) > all->info_b->max)
				all->info_b->max = *((int*)all->stack_b->content);
			if (*((int*)all->stack_b->content) < all->info_b->min)
				all->info_b->min = *((int*)all->stack_b->content);
		}
*/
//		printf("wr push we made it to end of id 'b'\n");

	}

	return (1);
}

int     ft_all_push_to_from(t_sorting *all, char id)
{
	int		ret1;		// for testing may be TMP

	if (!all)   // maybe also check if ID is a valid char?
		return (0);
	if (id == 'a')
	{
		while (all->stack_b != NULL)        // for some reason if not != NULL
		{									// it segfaults
			ret1 = ft_wr_push(all, 'b');
			if (ret1 != 1)
				return (ret1);
		}
	}
	else if (id == 'b')
	{
		while (all->stack_a != NULL)
		{
			ret1 = ft_wr_push(all, 'a');
			if (ret1 != 1)
				return (ret1);
		}
	}
	else
		return (2);
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
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(2)))
			return (0);
		++all->size_op;
	}
	else if (id == 'b')
	{
		result = ft_op_rotate(&all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(6)))
			return (0);
		++all->size_op;
	}
	else if (id == 'r')
	{
		result = ft_op_rotate_both(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(9)))
			return (0);
		++all->size_op;
	}
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
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(3)))
			return (0);
		++all->size_op;
	}
	else if (id == 'b')
	{
		result = ft_op_reverse_rotate(&all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(7)))
			return (0);
		++all->size_op;
	}
	else if (id == 'c')
	{
		result = ft_op_reverse_rotate_both(&all->stack_a, &all->stack_b);
		if (result != 1)
			return (result);
		if (!ft_ilstadd_back(&all->op_list, ft_ilstnew(10)))
			return (0);
		++all->size_op;
	}
	return (1);
}
