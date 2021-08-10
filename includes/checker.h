/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 01:06:55 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:51:33 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "both.h"

// for open for testing GNL
#include <fcntl.h>

int		ft_apply_ops(t_sorting *all, t_list **op_codes);
int		ft_parse_op_codes(t_list **op_codes);
int		ft_check_add_code(char *line, t_list **op_codes, char **valid_tab);

#endif
