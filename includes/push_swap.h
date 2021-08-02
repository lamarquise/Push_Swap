/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:57:40 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/02 14:03:51 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	// already has libft and stdio.h
# include "both.h"

// may end up adding my Wrapper Funcs in here

int		ft_my_sort(t_sorting *all);
int		ft_bubble_sort(t_sorting *all);


/*
**		Quick Sort
*/

int		ft_partition(t_sorting *all, int id, int size);
void	ft_b_quick_sort(t_sorting *all, int id, int size);


int		ft_my_quick_sort(t_sorting *all, int l, int r);
//int		ft_a_quick_sort(t_sorting *all, int l, int r);
int		ft_a_quick_sort(t_sorting *all, int p_index);

/*
**		QS Auxilary
*/

int		ft_get_mean(t_sorting *all, int id, int size);
void	*ft_lstlast_pointer(t_list *lst);
void	*ft_pointer_at_index(t_list *lst, int index);
int		ft_sort_end_cases(t_sorting *all, t_list **stack, char id);


#endif
