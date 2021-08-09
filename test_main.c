
#include <stdio.h>
#include "libft.h"
#include "simple_funcs.h"
#include "nlist_funcs.h"
#include "list_funcs.h"

int		main(int ac, char **av)
{

	printf("find numb %d\n", ft_findchar("hellow world\n", 'e'));

	t_list *tmp;
//	t_nlist *tmp;

/*
	tmp = NULL;
	tmp = ft_nlstnew(av[0], 0);

	printf("list read %s\n", ft_read_nlst_n(tmp, 0));
*/

	tmp = NULL;
	tmp = ft_lstnew(av[0]);

	printf("list read %s\n", (char*)tmp->content);

	return (0);
}
