/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:28:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/12 18:27:16 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_post_processing(t_sorting *all)
{
	t_ilist	*tmp;

	if (!all || !all->op_list)
		return (0);

	printf("in Post Processing, printing the ilist:\n");
	ft_print_ilist(all->op_list);
		// some giant algo to figure all this shit out...
	tmp = all->op_list;
	while (tmp->next->next->next)
	{
	// try adding a check in funcs called
		printf("in post processing loop! Printing tmp ilist:\n");
		ft_print_ilist(tmp);

		if ((tmp->next->num == 0 && tmp->next->next->num == 4) \
			|| (tmp->next->num == 4 && tmp->next->next->num == 0))
		{
			printf("post processing we should be removing next 2\n");
			ft_remove_next_two(all, &tmp);
		}
		else if ((tmp->next->num == 1 && tmp->next->next->num == 1) \
				|| (tmp->next->num == 5 && tmp->next->next->num == 5))
			ft_remove_next_two(all, &tmp);
		else if ((tmp->next->num == 2 && tmp->next->next->num == 3) \
				|| (tmp->next->num == 3 && tmp->next->next->num == 2))
			ft_remove_next_two(all, &tmp);
		else if ((tmp->next->num == 6 && tmp->next->next->num == 7) \
				|| (tmp->next->num == 7 && tmp->next->next->num == 6))
			ft_remove_next_two(all, &tmp);
		else if ((tmp->next->num == 1 && tmp->next->next->num == 5) \
				|| (tmp->next->num == 5 && tmp->next->next->num == 1))
			ft_replace_next_two_with_one(all, &tmp->next, 8);
		else if ((tmp->next->num == 2 && tmp->next->next->num == 6) \
				|| (tmp->next->num == 6 && tmp->next->next->num == 2))
			ft_replace_next_two_with_one(all, &tmp->next, 9);
		else if ((tmp->next->num == 3 && tmp->next->next->num == 7) \
				|| (tmp->next->num == 7 && tmp->next->next->num == 3))
			ft_replace_next_two_with_one(all, &tmp->next, 10);

		tmp = tmp->next;

	}

	// do i need a double pointer???


	return (1);
}
