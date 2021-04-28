/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/28 04:33:02 by ericlazo         ###   ########.fr       */
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

// parser.c
// create_stack.c
// swap.c



// OOOOHHHHHHH 
// we could have separate vars for info of Stack A and B!!!!!!
// Then generic funcs that update either, and we just send the right one!!!

typedef struct	s_stack_info
{
	int		max;
	int		min;
	int		mean;		// leave mean for now... could turn into "pivot"...

	int		size;
	int		rot;	// the idea being, if we store tmp elems at the bottom

//	t_list	*stack;		// not sure which is better...

}				t_stack_info;

	// wait, does it need to be in both? i mean it's only for the sorting right?
	// leave it for now...
typedef struct	s_mysort
{
	int				size_total;
	t_stack_info	*info_a;
	t_stack_info	*info_b;

/*	int		max_a;
	int		min_a;
	int		mean_a;		// leave mean for now... could turn into "pivot"...

	int		max_b;
	int		min_b;
	int		mean_b;

	int		size_total;
	int		size_a;
	int		size_b;

	int		rot_a;	// the idea being, if we store tmp elems at the bottom
	int		rot_b;	// we can reverse them knowing this, 0 is none
*/

	t_list	*stack_a;
	t_list	*stack_b;

}				t_mysort;		// t_stack *all;

// could make a t_quicksort_info


int			ft_create_stack(t_list **stack, int **tab, int size);


int			ft_parser(char **av, int **tab);



int			ft_swap(t_list **stack);
int			ft_swap_both(t_list **stack_a, t_list **stack_b);

int			ft_push_to_from(t_list **stack_to, t_list **stack_from);

	// not actually a thing... oops
//int			ft_push_both(t_list **stack_a, t_list **stack_b);

int			ft_rotate(t_list **stack);
int			ft_reverse_rotate(t_list **stack);

int			ft_rotate_both(t_list **stack_a, t_list **stack_b);
int			ft_reverse_rotate_both(t_list **stack_a, t_list **stack_b);


// Wrappers

int			ft_swap_wrapper(t_mysort *all, t_list **stack, char id);
int			ft_push_wrapper(t_mysort *all, char id);
int			ft_ratate_wrapper(t_mysort *all, char id);



// Utils Both
// Would rather not have this file, would like either to use funcs from Libft
// create and put in libft, but for now...

void		ft_free_int(void *content);


// Init Structs

int			ft_init_stack_info(t_stack_info *info, int size);
int			ft_prep_stack_info(t_stack_info *info, int *int_tab);


// Print Struct Status

void		ft_print_stack(t_list *stack);
void		ft_print_both_stacks(t_mysort *all);
void		ft_print_stack_info(t_stack_info *info);
void		ft_print_mysort_all(t_mysort *all);


#endif
