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

// Is Secure!
	// once again it has no leaks but no other checks...

int	ft_post_processing_p2(t_sorting *all, t_ilist **tmp)
{
	if (!all || !tmp)
		return (0);
	if (((*tmp)->next->num == 2 && (*tmp)->next->next->num == 3) \
			|| ((*tmp)->next->num == 3 && (*tmp)->next->next->num == 2))
		ft_remove_next_two(all, tmp);
	else if (((*tmp)->next->num == 6 && (*tmp)->next->next->num == 7) \
			|| ((*tmp)->next->num == 7 && (*tmp)->next->next->num == 6))
		ft_remove_next_two(all, tmp);
	else if (((*tmp)->next->num == 1 && (*tmp)->next->next->num == 5) \
			|| ((*tmp)->next->num == 5 && (*tmp)->next->next->num == 1))
		ft_replace_next_two_with_one(all, &(*tmp)->next, 8);
	else if (((*tmp)->next->num == 2 && (*tmp)->next->next->num == 6) \
			|| ((*tmp)->next->num == 6 && (*tmp)->next->next->num == 2))
		ft_replace_next_two_with_one(all, &(*tmp)->next, 9);
	else if (((*tmp)->next->num == 3 && (*tmp)->next->next->num == 7) \
			|| ((*tmp)->next->num == 7 && (*tmp)->next->next->num == 3))
		ft_replace_next_two_with_one(all, &(*tmp)->next, 10);
	return (1);
}

int	ft_post_processing(t_sorting *all)
{
	int		i;
	t_ilist	*tmp;

	if (!all || !all->op_list)
		return (0);
	tmp = all->op_list;
	while (tmp && tmp->next && tmp->next->next)
	{
		i = 0;
		if ((tmp->next->num == 0 && tmp->next->next->num == 4) \
			|| (tmp->next->num == 4 && tmp->next->next->num == 0))
			ft_remove_next_two(all, &tmp);
		else if ((tmp->next->num == 1 && tmp->next->next->num == 1) \
				|| (tmp->next->num == 5 && tmp->next->next->num == 5))
			ft_remove_next_two(all, &tmp);
		else if (!ft_post_processing_p2(all, &tmp))
			return (0);
		else
		{
			i = 1;
			tmp = tmp->next;
		}
		if (i == 0)
			tmp = all->op_list;
	}
	return (1);
}
