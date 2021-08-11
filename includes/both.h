/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/11 17:01:05 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

	// Don't need ?
# include <stdio.h>

	// NOT ANYMORE... sad
//# include "libft.h"
#include "minilib.h"

# define INTMIN -2147483648
# define INTMAX 2147483647

/*
	// do i need to swap val of PA and PB???
	PA = 0
	SA = 1
	RA = 2
	RRA = 3
	PB = 4
	SB = 5
	RB = 6
	RRB = 7
	SS = 8
	RR = 9
	RRR = 10
*/

typedef struct	s_sorting
{
	int				size_total;
	int				size_a;
	int				size_b;
	t_nlist			*stack_a;
	t_nlist			*stack_b;

	int				size_op;
	t_ilist			*op_list;

}				t_sorting;		// t_sorting *all;


/*
**		Creat Stack
*/

int			ft_print_inttab(int *tab, int size);
int			ft_create_stack(t_nlist **stack, int **int_tab, int size);
int			ft_free_nlist_elems(t_nlist **stack);

/*
**		Parsing
*/

int			ft_parser(char **av, int **tab, int i);

/*
**		Operations
*/

int			ft_op_swap(t_nlist **stack);
int			ft_op_swap_both(t_nlist **stack_a, t_nlist **stack_b);
int			ft_op_push_to_from(t_nlist **stack_to, t_nlist **stack_from);
int			ft_op_rotate(t_nlist **stack);
int			ft_op_reverse_rotate(t_nlist **stack);
int			ft_op_rotate_both(t_nlist **stack_a, t_nlist **stack_b);
int			ft_op_reverse_rotate_both(t_nlist **stack_a, t_nlist **stack_b);

/*
**	 Utils Both
*/
// Would rather not have this file, would like either to use funcs from Libft
// create and put in libft, but for now...

int			ft_strcmp_to_strtab(char *input, char **tab);
int			ft_is_sorted(t_nlist *stack);

/*
**		Free
*/

void		ft_free_int(void *content);
int			ft_free_int_tab(int **int_tab, int size);




/*
**		Print Struct Status
*/

void		ft_print_stack(t_nlist *stack);
void		ft_print_both_stacks(t_sorting *all);
//void		ft_print_stack_info(t_stack_info *info);
//void		ft_print_mysort_all(t_sorting *all);
//void		ft_print_inttab(int *tab, int size);


#endif
