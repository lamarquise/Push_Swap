/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/09 21:06:13 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

	// Don't need ?
# include <stdio.h>


# include "libft.h"

# define INTMIN -2147483648
# define INTMAX 2147483647




// only exists for the prototypes and structures that are needed for BOTH programs
	// checker and push_swap

// Should keep a list of the .c Files that go in here

// parsing.c
// create_stack.c
// swap.c
// init_structs.c
// parint_struct_status.c
// utils_both.c


	// this Struct is Obsolete
/*
typedef struct	s_stack_info
{
	int		max;
	int		min;
//	int		mean;		// leave mean for now... could turn into "pivot"...

	// we could store the total, like the sum of all the nums stored
	// in the stack, much easier to recalculate mean (if we need that...)

	int		size;

	// do i even use this? I think no
	//int		rot;	// the idea being, if we store tmp elems at the bottom

}				t_stack_info;
*/

typedef struct	s_sorting
{
	int				size_total;
	int				size_a;
	int				size_b;
//	t_stack_info	*info_a;
//	t_stack_info	*info_b;

	t_nlist			*stack_a;
	t_nlist			*stack_b;


	// do i want to keep a pointer to the Table of pointers to ints
	// in All? could be useful for freeing...
}				t_sorting;		// t_sorting *all;


/*
**		Push Swap Main
*/

int		ft_is_reverse_sorted(t_nlist *stack);
int		ft_rev_sort(t_sorting *all, int size);


/*
**		Creat Stack
*/

int			ft_print_inttab(int *tab, int size);
int			ft_create_stack(t_nlist **stack, int **int_tab, int size);
int			ft_free_nlist_elems(t_nlist **stack);


/*
**		Parsing
*/

int			ft_free_int_tab(int **int_tab, int size);
int			ft_parser(char **av, int **tab, int i);

// might move these to their own file
//int			ft_parse_op_codes(t_list **op_codes);
//int			ft_check_add_code(char *line, t_nlist **op_codes, char **valid_tab);

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

void		ft_free_int(void *content);
//void		ft_print_inttab(int *tab, int size);
int			ft_strcmp_to_strtab(char *input, char **tab);
int			ft_is_sorted(t_nlist *stack);

/*
**		Print Struct Status
*/

void		ft_print_stack(t_nlist *stack);
void		ft_print_both_stacks(t_sorting *all);
//void		ft_print_stack_info(t_stack_info *info);
//void		ft_print_mysort_all(t_sorting *all);

/*
**		Init Structs	// OBSOLETE !!!
*/

//int			ft_init_stack_info(t_stack_info *info, int size);
//int			ft_prep_stack_info(t_stack_info *info, int *int_tab);

/*
**		Wrappers	Moved
*/

/*
int			ft_wr_swap(t_sorting *all, char id);
int			ft_wr_push(t_sorting *all, char id);
int			ft_wr_rotate(t_sorting *all, char id);
int			ft_wr_reverse_rotate(t_sorting *all, char id);
//int			ft_all_push_to_from(t_nlist **stack_to, t_nlist **stack_from);
 int			ft_all_push_to_from(t_sorting *all, char id);
*/


#endif
