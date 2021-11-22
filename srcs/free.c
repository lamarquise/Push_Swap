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


// What do we want in here...
/*

	We want to free nlists -> The Stacks
	We want to free int_tab
	We want to free list -> Op_Codes in Checker
	We want to free iLists -> op codes in Push Swap

	We may need to free the list of Pre Writing Opcodes (not sure how it
	will be stored



*/



	// This might actually be fine...
		// though way too long and unnecessary...
 	// using a dumb name but could change it and add to libft later...
int		ft_free_int_tab(int **int_tab, int size)
{
	int	i;
	int	*tmp;

	if (!int_tab || !*int_tab)
		return (1);		// so it doesn't crash if no int tab
	i = 0;
	tmp = *int_tab;
	while (i < size)
	{
//		free(&(tmp[i]));
			// Is this good enough ????
			// IDK if this does what i want...
	//	free((*int_tab)[i]);


	// This crashes shit, don't do it...
//		free((int_tab)[i]);

		++i;
	}

	// or is it just
	free(*int_tab);		// ????

	return (1);
}



// seems like a stupid func, but need it for lstclear, may make a whole new system later
	// such a dumb function...
	// in our case content is an int*
	// should i just do int *content?
void	ft_free_int(void *content)
{

	content = NULL;

}


int		ft_free_nlist_elems(t_nlist **stack)
{
	t_nlist	*tmp;

	if (!stack)
		return (1);		// if nothing to do we gucci
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	// free (stack too?) not sure...
	// don't free stack because it's allocated in struct t_sorting meaning when *all
	// gets freed its vars get freed, so don't touch or would be a double free.
 	return (1);
}

int		ft_free_ilist(t_nlist **stack)
{
	t_nlist	*tmp;

	// shouldn't it be if (!*stack) ??? it's 1 and
	// (!stack) is 0 ???
	if (!stack)
		return (1);		// if nothing to do we gucci
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	// free (stack too?) not sure...
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


