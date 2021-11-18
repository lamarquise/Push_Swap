/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:43:28 by ericlazo          #+#    #+#             */
/*   Updated: 2021/11/09 18:17:12 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

// This simple split should only break up numbers with 1 space between each...

// this needs to be fixed, i don't take into account + or - ...

	// this does both the checking of the list of numbers and the counting of # of #s
int	ns(char *str)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == ' ')
			++numbers;
		++i;


/*

		if ((s[i] >= '0' && s[i] <= '9') && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			++numbers;
		else if (s[i] == ' ' && (!(s[i + 1] >= '0' && s[i + 1] <= '9') \
				&& s[i + 1] != '\0'))
			return (-1);
		++i;
*/
	}
	return (numbers + 1);
}

int		nl(char *s, int start)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[start + i] && s[start + i] != ' ')
		++i;
	return (i + 1);
}

int		fill_sret(char **ret, char *s, int a)
{
	int		b;
	int		d;

	if (!ret || !s)
		return (-1);
	b = 0;
	while (s[a])
	{
		if (s[a] == ' ')
			++a;
		else
		{
			d = 0;
			ret[b] = ft_memalloc(sizeof(char) * nl(s, a));
			if (!ret[b])
				return (-1);
			while (s[a] && s[a] != ' ')
				ret[b][d++] = s[a++];
			ret[b++][d] = '\0';
		}
	}
	return (b);
}

char	**ft_simple_split(char *s)
{
	int		a;
	int		b;
	int		numbers;
	char	**ret;

	if (!s)
		return (NULL);
	a = 0;
	b = 0;
	numbers = ns(s);
//	printf("numbers: %d\n", numbers);
	if (numbers == -1)
		return (NULL);
	ret = (char **)ft_memalloc(sizeof(char *) * numbers);
	if (!ret)
		return (NULL);
	b = fill_sret(ret, s, a);
	if (b == -1)
	{
		ft_free_strtab(ret);
		return (NULL);
	}
	return (ret);
}

// There is no way this shit works!!!!!
// Wait ok nvm this might be ok...
	// what happens when we give it " 23 34 543 433"
	// or "2341 1234 234 "
int		ft_check_str(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_findchar("+-0123456789", str[0]) == -1)
		return (0);
	// find a way to check if str[i] is + or - then must be nothing or empty before
	while (str[i])
	{
		// saying if current char is + or - then next must be 0-9
		if ((str[i] == '+' || str[i] == '-') \
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		else if (str[i] == ' ' && str[i + 1] \
				&& ft_findchar("+-0123456789", str[i + 1]) == -1)
		{
			printf("space and nothing after\n");
			return (0);
		}
		else if (ft_findchar("+- 0123456789", str[i]) == -1)
		{
//			printf("check str and not a valid char\n");
			return (0);
		}
		++i;
	}
	return (1);
}

int		ft_fill_int_tab(char *str, int **int_tab)
{
	int		a;
	int		i;
	int		neg;
	long	tmp;

	a = 0;
	i = 0;
	neg = 1;
	tmp = 0;
	// yea this shit is a disaster...
	// fucks up if there's only 1 and it's not valid...
	while (str[a])
	{
		if (str[a] == ' ')
		{
/*			ft_print_inttab(*int_tab, i);
			if (tmp < INTMIN || tmp > INTMAX)
			{
				printf("not a valid int\n");
				return (0);
			}
			(*int_tab)[i] = tmp * neg;
			++i;
			neg = 1;
			tmp = 0;
*/			++a;
		}
		if (str[a] == '-' || str[a] == '+')
		{
			if (str[a] == '-')
				neg = -1;
			++ a;
		}
		while (str[a] >= '0' && str[a] <= '9')
		{
			tmp = tmp * 10 + (str[a] - 48);
			++a;
		}
//		ft_print_inttab(*int_tab, i);
		tmp *= neg;
		if (tmp < INTMIN || tmp > INTMAX)
		{
			printf("tmp: %ld not valid\n", tmp);
			return (0);
		}
		(*int_tab)[i] = tmp;
		++i;
		neg = 1;
		tmp = 0;
	}
//	(*int_tab)[i] = tmp * neg;
	return (1);
}



	// return size
	// assuming int_tab is empty
int		ft_split_ints(char *str, int **int_tab)
{
	int	a;
	int	size;

//	printf("split ints str: |%s|\n", str);
//	printf("start split\n");
	if (!str)
		return (0);
	if (!str[0])
		return (-1);
	//if (!str || !int_tab || !ft_check_str(str))
	if (!int_tab || !ft_check_str(str))
	{
//		printf("check str returned bad\n");
		return (-2);
	}
	a = 0;
	size = ns(str);
	printf("in split ints int tab size: %d\n", size);
	if (size < 1)
		return (-3);
	*int_tab = ft_memalloc(sizeof(int *) * size);
	if (!*int_tab)
		return (-4);

//	printf("made it to fill int tab\n");
 	if (!ft_fill_int_tab(str, int_tab))
		return (-5);
//	printf("end split\n");

	return (size);
}







