/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:57:40 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/11 17:17:18 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	// already has libft and stdio.h
# include "both.h"


/*
**		Pre Sorting
*/

int		ft_is_reverse_sorted(t_nlist *stack);
int		ft_rev_sort(t_sorting *all, int size);
int		ft_sort_by_index(t_sorting *all);

/*
**		Quick Sort
*/

int		ft_partition(t_sorting *all, int id, int size);
int		ft_my_quick_sort(t_sorting *all, int id, int size);
int		ft_first_partition(t_sorting *all, int size);
int		ft_start_push_swap(t_sorting *all, int size);

/*
**		Minisort
*/

int		ft_get_median(t_sorting *all, int id, int size);
	// mean may be obsolete
int		ft_get_mean(t_sorting *all, int id, int size);
void	*ft_lstlast_pointer(t_nlist *lst);
void	*ft_pointer_at_index(t_nlist *lst, int index);
int		ft_sort_end_cases(t_sorting *all, t_nlist **stack, char id);
int		ft_minisort(t_sorting *all, int id, int size);

/*
**		Wrapper Functions
*/

int		ft_wr_swap(t_sorting *all, char id);
int		ft_wr_push(t_sorting *all, char id);
int		ft_all_push_to_from(t_sorting *all, char id);
int		ft_wr_rotate(t_sorting *all, char id);
int		ft_wr_reverse_rotate(t_sorting *all, char id);

/*
**		iList More
*/

int		ft_print_ilist(t_ilist *lst);
int		ft_print_op_codes(t_ilist *op_codes);
int		ft_remove_next_two(t_sorting *all, t_ilist **cur);
int		ft_replace_next_two_with_one(t_sorting *all, t_ilist **cur, int rep);

/*
**		Post Processing
*/

int		ft_post_processing(t_sorting *all);

	// Obsolete
int		ft_my_sort(t_sorting *all);
int		ft_bubble_sort(t_sorting *all);


#endif
