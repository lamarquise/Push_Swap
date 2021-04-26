/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/04/27 00:51:28 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


	// do not love the name, would prefere these sort of funcs come from or be
	// put in the Libft...

#include "both.h"

// seems like a stupid func, but need it for lstclear, may make a whole new system later
	// such a dumb function...
	// in our case content is an int*
	// should i just do int *content?
void	ft_free_int(void *content)
{

	content = NULL;

}




