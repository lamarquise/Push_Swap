/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/28 13:00:49 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

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


typedef struct	s_stack_info
{
	int		max;
	int		min;
	int		mean;		// leave mean for now... could turn into "pivot"...

	// we could store the total, like the sum of all the nums stored
	// in the stack, much easier to recalculate mean (if we need that...)

	int		size;
	int		rot;	// the idea being, if we store tmp elems at the bottom

}				t_stack_info;

typedef struct	s_sorting
{
	int				size_total;
	t_stack_info	*info_a;	// could call it metadata, or meta...
	t_stack_info	*info_b;

	t_list	*stack_a;
	t_list	*stack_b;

}				t_sorting;		// t_sorting *all;

/*
**		Creat Stack
*/

int			ft_print_inttab(int *tab, int size);
int			ft_create_stack(t_list **stack, int **tab, int size);


/*
**		Parsing
*/

int			ft_parser(char **av, int **tab);

// might move these to their own file
int			ft_parse_op_codes(t_list **op_codes);
int			ft_check_add_code(char *line, t_list **op_codes, char **valid_tab);

/*
**		Operations
*/

int			ft_op_swap(t_list **stack);
int			ft_op_swap_both(t_list **stack_a, t_list **stack_b);

int			ft_op_push_to_from(t_list **stack_to, t_list **stack_from);
//int			ft_all_push_to_from(t_list **stack_to, t_list **stack_from);
 int			ft_all_push_to_from(t_sorting *all, char id);
	// not actually a thing... oops
//int			ft_push_both(t_list **stack_a, t_list **stack_b);

int			ft_op_rotate(t_list **stack);
int			ft_op_reverse_rotate(t_list **stack);

int			ft_op_rotate_both(t_list **stack_a, t_list **stack_b);
int			ft_op_reverse_rotate_both(t_list **stack_a, t_list **stack_b);


/*
**		Wrappers
*/

int			ft_wr_swap(t_sorting *all, t_list **stack, char id);
int			ft_wr_push(t_sorting *all, char id);
int			ft_wr_ratate(t_sorting *all, char id);



// Utils Both
// Would rather not have this file, would like either to use funcs from Libft
// create and put in libft, but for now...

void		ft_free_int(void *content);
//void		ft_print_inttab(int *tab, int size);
int			ft_strcmp_to_strtab(char *input, char **tab);


/*
**		Init Structs
*/

int			ft_init_stack_info(t_stack_info *info, int size);
int			ft_prep_stack_info(t_stack_info *info, int *int_tab);

/*
**		Print Struct Status
*/

void		ft_print_stack(t_list *stack);
void		ft_print_both_stacks(t_sorting *all);
void		ft_print_stack_info(t_stack_info *info);
void		ft_print_mysort_all(t_sorting *all);


#endif
