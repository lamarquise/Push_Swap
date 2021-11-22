/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:04:34 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 17:09:16 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Is Secure!
	// Not gonna bother adding an shitload of if-checks...

int	ft_split_part(t_sorting *all, int id, int part_size, int med)
{
	int		rot_count;

	rot_count = 0;
	while (part_size)
	{
		if ((id == 1 && all->stack_b->index > med) \
			|| (id == 0 && all->stack_a->index <= med))
		{
			ft_wr_push(all, id + 'a');
			--part_size;
		}
		else
		{
			ft_wr_rotate(all, id + 'a');
			++rot_count;
		}
	}
	return (rot_count);
}

int	ft_partition(t_sorting *all, int id, int size)
{
	int		med;
	int		rot_count;
	int		part_size;

	med = ft_get_median(all, id, size);
	if (id)
		part_size = (size + 1) / 2;
	else
		part_size = size / 2;
	size -= part_size;
	rot_count = ft_split_part(all, id, part_size, med);
	if ((id == 0 && size != all->size_a) || (id == 1 && size != all->size_b))
	{
		while (rot_count--)
			ft_wr_reverse_rotate(all, id + 'a');
	}
	return (part_size);
}

	// yea fuck the if-checks, they aren't used ubiquitously so it doesn't matter...
int	ft_my_quick_sort(t_sorting *all, int id, int size)
{
	int	part_size;

	if (size < 4)
		ft_minisort(all, id, size);
	else
	{
		part_size = ft_partition(all, id, size);
		if (id)
		{
			ft_my_quick_sort(all, 0, part_size);
			ft_my_quick_sort(all, 1, size - part_size);
		}
		else
		{
			ft_my_quick_sort(all, 0, size - part_size);
			ft_my_quick_sort(all, 1, part_size);
		}
	}
	return (1);
}

int	ft_first_partition(t_sorting *all, int size)
{
	int		med;
	int		push_count;

	med = size / 2;
	push_count = size / 2;
	while (push_count)
	{
		if (all->stack_a->index <= med)
		{
			ft_wr_push(all, 'a');
			--push_count;
		}
		else
			ft_wr_rotate(all, 'a');
		if (all->size_b > 1 && all->stack_b->index < med / 2)
		{
			ft_wr_rotate(all, 'b');
		}
	}
	return (med);
}

	// this is fucking idiotic i apply my algo more than once in certain cases
		// like in rev sorted size 3...
int	ft_start_push_swap(t_sorting *all, int size)
{
	int	part_size;

//	printf("made it to start of Quicksort\n");
	if (ft_is_sorted(all->stack_a))
		return (1);
	else if (ft_is_reverse_sorted(all->stack_a)) //why secure, there are no checks...
		ft_rev_sort(all);
	else if (size < 4)
		ft_threesort(all, 0, size);
	else
	{
		// secure? I guess not... not really worth it...
		part_size = ft_first_partition(all, size);
		ft_my_quick_sort(all, 0, size - part_size);
		ft_my_quick_sort(all, 1, part_size);
	}
//	printf("in end of QS\n");
	return (1);
}
