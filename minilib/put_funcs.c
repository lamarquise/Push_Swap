/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:32:43 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 20:19:21 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long			nb;
	unsigned char	*ret;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ret = (unsigned char *)(nb % 10 + 48);
	write(1, &ret, 1);
}

void	ft_putstr(char const *s)
{
	int		a;

	a = 0;
	if (!s)
		return ;
	while ((char)s[a])
	{
		write(1, (void *)&s[a], 1);
		++a;
	}
}
