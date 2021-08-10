/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ericlazo <erlazo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:33:21 by ericlazo          #+#    #+#             */
/*   Updated: 2021/08/10 20:25:25 by ericlazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

//# include something for something

/*
**		Put Funcs
*/

void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s)

/*
**		GNL
*/


/*
**		List Funcs
*/

void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
t_list		*ft_lstnew(void *content);
void		ft_print_elem(t_list *elem);

/*
**		nList Funcs
*/

int			ft_nlstadd_back(t_nlist **lst, t_nlist *new);
int			ft_nlstadd_front(t_nlist **lst, t_nlist *new);
t_nlist		*ft_nlstnew(void *content, int index);
int			ft_nlstdel_all(t_nlist **lst);

/*
**		Stand Alone nList Funcs
*/

int			ft_nlstdel_n_one(t_nlist **lst, int n);

/*
**		Str Funcs
*/

int			ft_findchar(char *str, char c);
long		ft_error_msg(char *str, int ret);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);

/*
**		Big Str Funcs
*/

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_fill_with(char this, int len);
void		*ft_memalloc(size_t size);

/*
**		Atoi Funcs (full)
*/

int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/*
**		Tab Funcs
*/

int			ft_free_strtab(char **tab);
int			ft_print_strtab(char **tab);

/*
**		Stand Alone Files
*/

char		**ft_split(char const *s, char *set);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
