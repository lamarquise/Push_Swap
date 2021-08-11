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

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_nlist
{
	int				index;
	void			*content;
	struct s_nlist	*next;
}				t_nlist;

typedef struct s_ilist
{
	int				num;
	struct s_ilist	*next;
}				t_ilist;

/*
**		Put Funcs
*/

void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putnbrnl(int nbr);
void		ft_putstr(char const *s);
long		ft_scott_free(char **str, int ret);

/*
**		GNL
*/

int			ft_gnl(char **line, int fd);

/*
**		GNL Utils
*/

size_t		ft_sstrlen(const char *s);
int			ft_sfindchar(char *str, char c);
int			ft_ibzero(void *s, size_t n);

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
**		iList Funcs
*/

t_ilist		*ft_ilstnew(int num);
int			ft_ilstadd_back(t_ilist **lst, t_ilist *new);
int			ft_ilstadd_front(t_ilist **lst, t_ilist *new);
int			ft_ilstdel_all(t_ilist **lst);


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
// move later
char		*ft_strchr(const char *s, int c);

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
