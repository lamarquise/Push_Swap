/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:06:55 by ericlazo          #+#    #+#             */
/*   Updated: 2021/07/28 12:32:50 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

//#include "libft.h"	// nope, it's in both.h
#include "both.h"

// for open for testing GNL
#include <fcntl.h>

//int		ft_apply_ops(t_list **stack_a, t_list **stack_b);
int		ft_apply_ops(t_sorting *all, t_list **op_codes);
// i think this goes here...
//int		ft_parse_op_codes(t_list *op_codes);

#endif
