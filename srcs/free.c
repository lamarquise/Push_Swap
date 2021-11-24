/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 04:06:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/31 18:14:13 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// Is Secure!
	// But do i need the funcs at the end or should i delete them...

int	ft_free_int_tab(int **int_tab)
{
	if (!int_tab || !*int_tab)
		return (1);
	free(*int_tab);
	return (1);
}

int	ft_free_nlist_elems(t_nlist **stack)
{
	t_nlist	*tmp;

	if (!stack)
		return (1);
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	return (1);
}

int	ft_free_list_of_str(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return (1);
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	return (1);
}
