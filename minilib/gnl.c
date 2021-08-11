/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 00:09:33 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/11 02:50:18 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"


static char	*fill_s(char *s, char **line, ssize_t i)
{
	char	*p;

	p = NULL;
	*line = ft_strsub(s, 0, (size_t)i++);
	if (!*line)
		return (NULL);
	p = ft_strsub(s, i, ft_sstrlen(s) - (size_t)i);
	if (!p)
		return (NULL);
	free(s);	// i'm just gonna assume this free should work...
//	s = NULL;
//	s = p;
	return (p);
}
/*
static char	*fill_from_buffer(char *s, char **line, ssize_t i, char *b)
{
	char *p;

	p = NULL;
	if (i > 0)
	{
		p = ft_gstrjoin(&s, b);
		if (!p)
			return (NULL);
	}
	if (s && s[0] && ++i == 1 && !*line)
	{
		*line = ft_gstrjoin(&s, (void*)0);
		if (!*line)
			return (NULL);
	}
//	if (i < 1 && !(*line))
//	{
//		*line = ft_strsub(NULL, 0, 0);
//		if (!*line)
//			return (-1);
//	}

	free(s);		// IDK if i do that here
	return (p);
}
*/

int	ft_gnl(char **line, int fd)
{
	static char	*s;
	ssize_t		i;
	char		*p;
	char		b[17];

	p = NULL;
	i = ft_sfindchar(s, '\n');
	if (i != -1)
	{
		s = fill_s(s, line, i);
		if (!s)
			return (-1);
		return (1);
	}
/*	if ((i = ft_sfindchar(s, '\n')) != -1)
	{
		if (!(*line = ft_strsub(s, 0, (size_t)i++)) \
			|| (!(p = ft_strsub(s, i, ft_sstrlen(s) - (size_t)i))))
			return (-1);
		free(s);
		s = p;
		return (1);
	}
*/

// This shit works too
// Still worried about Leaks from this end too
// no idea how to put in other funcs...
		// I don't know how to translate this
		// (i = read(fd, b, 16)) < -1

	if (!line || !ft_ibzero(b, 17))
		return (-1);
	i = read(fd, b, 16);
	if (i < 0)
		return (-1);

//	s = fill_from_buff(s, line, i, b);
//	if (!s)
//		return (-1);


	if (i > 0)
	{
		p = ft_gstrjoin(&s, b);
		if (!p)
			return (-1);
	}
	if (s && s[0] && ++i == 1 && !*line)
	{
		*line = ft_gstrjoin(&s, (void*)0);
		if (!*line)
			return (-1);
	}


	if (i < 1 && !(*line))
	{
		*line = ft_strsub(NULL, 0, 0);
		if (!*line)
			return (-1);
	}

/*
	if (!line || !ft_ibzero(b, 17) || (i = read(fd, b, 16)) < -1
		|| (i > 0 && !(p = ft_gstrjoin(&s, b)))
		|| (s && s[0] && ++i == 1 && !(*line = ft_gstrjoin(&s, (void*)0)))
		|| (i < 1 && !(*line) && !(*line = ft_strsub(NULL, 0, 0))) || i < 0)
		return (-1);

*/


	free(s);
	s = p;


	return ((i > 0) ? ft_gnl(line, fd) : 0);
}
