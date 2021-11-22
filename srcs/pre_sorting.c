/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:40:15 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 17:12:53 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Is Secure!

// seems secure, doesn't mess with memory
int		ft_is_reverse_sorted(t_nlist *stack)
{
	t_nlist	*tmp;

//	printf("in is it REV sorted\n");
	if (!stack)
		return (0);		// ret 0? like what if there's no list, is that bad?
	tmp = stack;
	while (tmp->next)
	{
		// i think this is good enough
		if (*((int*)tmp->content) < *((int*)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
//	printf("end of is it REV sorted\n");
	return (1);
}

// need to secure this i think, the WR calls.
int		ft_rev_sort(t_sorting *all, int size)
{
//	printf("in do REV Sort, size var: %d\n", size);
	// swap and push to b
	// then push all back
	size = 0;
	while (all->size_a > 3)
	{
//		printf("in REV sort loop\n");
		ft_wr_reverse_rotate(all, 'a');
		ft_wr_push(all, 'a');
	}
	if (!ft_minisort(all, 'a', 3))
		return (0);
	ft_all_push_to_from(all, 'a');
//	printf("in end of do REV sort, printing stack:\n");
//	ft_print_both_stacks(all);
	return (1);
}



// pretty sure this checks for duplicates :)
// single *stack? not **stack?
int		ft_sort_by_index(t_sorting *all)
{
	t_nlist	*cur;
	t_nlist	*tmp;
	int		i;
	int		j;

	if (!all)
		return (0);
	i = all->size_total;
	cur = all->stack_a;
	while (i)
	{
		cur->index = 1;
		tmp = all->stack_a;
		j = all->size_total;
		while (j)
		{
			if (*((int*)tmp->content) < *((int*)cur->content))
				++cur->index;
			else if (*((int*)tmp->content) == *((int*)cur->content) \
				&& tmp != cur)
			{
			//	printf("sort by index error int is equal: %d\n", *((int*)tmp->content)); 
				return (0);
			}
			tmp = tmp->next;
			--j;
		}
		cur = cur->next;
		--i;
	}

	return (1);
}



