/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:00:47 by erlazo            #+#    #+#             */
/*   Updated: 2021/08/10 20:15:15 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	ret = (char *)malloc(sizeof(void) * size);
	if (!ret)
		return (NULL);
	while (a < size)
	{
		ret[a] = '\0';
		++a;
	}
	return ((void *)ret);
}
