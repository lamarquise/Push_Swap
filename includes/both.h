/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 14:51:31 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

//#include <stdio.h> // TMP for testing

# include "minilib.h"

# define INTMIN -2147483648
# define INTMAX 2147483647

/*
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

typedef struct s_sorting
{
	int				size_total;
	int				size_a;
	int				size_b;
	t_nlist			*stack_a;
	t_nlist			*stack_b;

	int				size_op;
	t_ilist			*op_list;

}				t_sorting;

/*
**		Creat Stack
*/

int			ft_print_inttab(int *tab, int size);
int			ft_create_stack(t_nlist **stack, int **int_tab, int size);

/*
**		Parsing
*/

int			ft_check_is_number_full_str(char *str);
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

int			ft_strcmp_to_strtab(char *input, char **tab);
int			ft_is_sorted(t_nlist *stack);
int			ft_satoi(const char *str, int *num);

/*
**	 Split Ints List
*/

int			ns(char *str);
int			ft_check_str(char *str);
int			ft_fill_int_tab_p2(char *str, int *neg, int a);
int			ft_fill_int_tab(char *str, int **int_tab);
int			ft_split_ints(char *str, int **int_tab);

/*
**		Free
*/

void		ft_free_int(void *content);
int			ft_free_int_tab(int **int_tab);
int			ft_free_nlist_elems(t_nlist **stack);
int			ft_free_ilist(t_nlist **stack);
int			ft_free_list_of_str(t_list **lst);

/*
**		Print Struct Status
*/

void		ft_print_stack(t_nlist *stack);
void		ft_print_both_stacks(t_sorting *all);

#endif
