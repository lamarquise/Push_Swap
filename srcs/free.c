/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 04:06:04 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 04:24:59 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"


// What do we want in here...
/*

	We want to free nlists -> The Stacks
	We want to free int_tab
	We want to free list -> Op_Codes

	We may need to free the list of Pre Writing Opcodes (not sure how it
	will be stored



*/



 	// using a dumb name but could change it and add to libft later...
int		ft_free_int_tab(int **int_tab, int size)
{
	int	i;

	if (!int_tab)
		return (1);		// so it doesn't crash if no int tab
	i = 0;

	while (i < size)
	{
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





