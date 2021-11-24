/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:57:40 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 17:32:59 by erlazo           ###   ########.fr       */
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
int		ft_rev_sort(t_sorting *all);
int		ft_sort_by_index(t_sorting *all);

/*
**		Quick Sort
*/

int		ft_split_part(t_sorting *all, int id, int part_size, int med);
int		ft_partition(t_sorting *all, int id, int size);
int		ft_my_quick_sort(t_sorting *all, int id, int size);
int		ft_first_partition(t_sorting *all, int size);
int		ft_start_push_swap(t_sorting *all, int size);

/*
**		Minisort
*/

void	ft_minisort_a_p2(t_sorting *all, int size);
int		ft_minisort_a(t_sorting *all, int size);
int		ft_minisort_b(t_sorting *all, int size);
int		ft_minisort(t_sorting *all, int id, int size);

/*
**		Minisort Part 2
*/

int		ft_get_median_p2(t_nlist *stack, int size);
int		ft_get_median(t_sorting *all, int id, int size);
void	ft_threesort_p2(t_sorting *all, t_nlist *stack);
int		ft_threesort(t_sorting *all, int id, int size);
 
/*
**		Wrapper Functions
*/

int		ft_wr_swap(t_sorting *all, char id);
int		ft_wr_push_p2(t_sorting *all);
int		ft_wr_push(t_sorting *all, char id);
int		ft_all_push_to_from(t_sorting *all, char id);

/*
**		Wrapper Functions Rotate
*/

int		ft_wr_rotate_p2(t_sorting *all, char id);
int		ft_wr_rotate(t_sorting *all, char id);
int		ft_wr_reverse_rotate_p2(t_sorting *all, char id);
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

void	ft_post_processing_p2(t_sorting *all, t_ilist **tmp);
int		ft_post_processing(t_sorting *all);

	// Obsolete
int		ft_my_sort(t_sorting *all);
int		ft_bubble_sort(t_sorting *all);


#endif
