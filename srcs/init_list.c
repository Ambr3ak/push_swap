#include "../inc/push.h"

int	lst_add(int ptr, t_list_int **stack)
{
	t_list_int	*elem;

	elem = ft_lstnew_int((ptr));
	if (!(elem))
	{
		return (ERR_ARG);
	}
	if (!(stack))
		*stack = elem;
	else
		ft_lstadd_back_int(stack, elem);
	return (ptr);
}

int	init_lst(t_swap *data, int *tmp, t_list_int **stack)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		
		if (!lst_add(tmp[i], stack))
			return (ERR_LIST);
		if (i == data->lst_size)
			break;
		i++;
	}

	return (1);
}

int init_swap(t_swap *data, char **argv, int argc)
{
    data->arg = malloc_list(data, sizeof(t_arg));
	data->a = NULL;
	data->b = NULL;
	data->arg->stack_k = NULL;
	data->smallst = -1;
    if (!data->arg)
	{
        return (ERR_MALLOC);
	}
	data->arg->nb = argc;
	data->lst_size = argc - 1;
	data->error = 0;
    return (parser_nb(data, argv));
}

void init_tab(t_list_int *list, int *tab)
{
    int i;
    t_list_int *lst;

    lst = list;
    i = 0;
	while (lst)
	{
		tab[i] = (int)lst->content;
        lst = lst->next;
        i++;
	}
}