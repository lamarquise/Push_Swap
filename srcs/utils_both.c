/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/02 12:10:40 by ericlazo         ###   ########.fr       */
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


// this could actually be worth putting in Libft if not already there...
// i actually already made one of these...
/*
void	ft_print_inttab(int *tab, int size)
{
	int		i;

	if (!tab)
		return;
	i = 0;
	while (i < size)
		ft_putnbr(tab[i++]);


}
*/


// this might be another one i should add to Libft...
// basically i want a func þ compares a string to a table to strings

int		ft_strcmp_to_strtab(char *input, char **tab)
{
	int		i;

	if (!input || !tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(input, tab[i]))
			return (1);
		++i;
	}


	return (0);
}





