/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:56:32 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/04 19:42:52 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
	{
			// i think this is good enough
		if (*((int*)tmp->content) > *((int*)tmp->next->content))
			return (0);
		tmp = tmp->next;
	}

	return (1);
}

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


int		ft_first_partition(t_sorting *all, int size)
{
	int		c;
	int		pivot;
	int		part_size;

	c = 0;
	part_size = 0;
	pivot = ft_get_mean(all, 0, size);
	while (c < size)
	{
		if (*((int*)all->stack_a->content) <= pivot)
		{
			ft_wr_push(all, 'a');
			++part_size;
		}
		else if (*((int*)all->stack_a->content) > pivot)
			ft_wr_rotate(all, 'a');
		++c;
	}

	return (part_size);
}


	// we can make it an int and return 1 or whatever if we want later...
void	ft_start_push_swap(t_sorting *all, int size)
{
	int		part_size;

	if (ft_is_sorted(all->stack_a))
		return ;
	else if (ft_is_reverse_sorted(all->stack_a))
		ft_rev_sort(all, size);
	else if (size < 4)
		ft_minisort(all, 0, size);
	else
	{
		part_size = ft_first_partition(all, size);
	//	printf("Start Push Swap, part_size: %d\n", part_size);

//		printf("--- Partitioned stacks in Starting Push Swap\n");
//		ft_print_both_stacks(all);

		ft_my_quick_sort(all, 0, size - part_size);
		ft_my_quick_sort(all, 1, part_size);
	}
}




int		main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*int_tab;

	t_sorting		all;	// no need to free but should free 
							// things in it (if pointers)

//	t_stack_info	info_a;
//	t_stack_info	info_b;

//	printf("|-------Push Swap Start-------|\n");
	if (ac < 2)
		return (ft_error_msg("ERROR: no list of ints\n", 0));

	stack_a = NULL;
	stack_b = NULL;
	int_tab = NULL;

	if (!(all.size_total = ft_parser(av, &int_tab)))
		return (ft_error_msg("ERROR: Bad List\n", 0));


	if (!ft_create_stack(&stack_a, &int_tab, all.size_total))
	{
		// may need to free some things...
		return (ft_error_msg("ERROR: failed to create the stack\n", 0));
	}


// so far this is all identical to checker.c


	if (!ft_init_stack_info(&info_a, all.size_total) || !ft_init_stack_info(&info_b, 0))
		return (ft_error_msg("ERROR: Failed to init stack_infos\n", 0));

//	all.info_a = &info_a;
//	all.info_b = &info_b;
	all.stack_a = stack_a;
	all.stack_b = stack_b;
	all.size_a = all.size_total;
	all.size_b = 0;

	// we setup stack info for Stack A
//	if (!ft_prep_stack_info(&info_a, int_tab) || !ft_prep_stack_info(&info_b, int_tab))
//		return (ft_error_msg("ERROR: Failed to prep mysort_info\n", 0));

	int		ret1;

	ret1 = 0;
//	ret1 = ft_bubble_sort(&all);
	ft_start_push_swap(&all, all.size_total);

//	printf("End of Push Swap\n");
//	ft_print_both_stacks(&all);


	// this is also like checker.c

	ft_lstclear(&stack_a, &ft_free_int);

//	printf("|-------Push Swap End-------|\n");

	return (0);
}
