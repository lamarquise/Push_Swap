/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:37:36 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/27 01:29:45 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H

# include <stdio.h>


# include "libft.h"

// only exists for the prototypes and structures that are needed for BOTH programs
	// checker and push_swap

// Should keep a list of the .c Files that go in here

// parser.c
// create_stack.c
// swap.c




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






// Utils Both
// Would rather not have this file, would like either to use funcs from Libft
// create and put in libft, but for now...

void		ft_free_int(void *content);







#endif
