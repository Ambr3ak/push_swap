#include "../inc/push.h"

int	lst_add(t_arg *arg, int ptr)
{
	t_list_int	*elem;

	elem = ft_lstnew_int((ptr));
	if (!(elem))
	{
		return (ERR_ARG);
	}
	if (!(arg->num_a))
		arg->num_a = elem;
	else
		ft_lstadd_back_int(&arg->num_a, elem);
	return (ptr);
}

int	init_lst(t_arg *arg, int *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		
		if (!lst_add(arg, tmp[i]))
			return (ERR_LIST);
		if (i == arg->nb - 1)
			break;
		i++;
	}
	//sa(&arg->num_a);

	//ra(&arg->num_a);
	//ra(&arg->num_a);
	//pb(&arg->num_a, &arg->num_b);
	pb(&arg->num_a, &arg->num_b);
	pa(&arg->num_a, &arg->num_b);
	//ss(&arg->num_a, &arg->num_b);
	printf("A STACK\n");
	while (arg->num_a)
	{
		printf("%d -> ", (int)arg->num_a->content);
        arg->num_a = arg->num_a->next;
	}
	printf("\nB STACK\n");
	while (arg->num_b)
	{
		printf("%d -> ", (int)arg->num_b->content);
        arg->num_b = arg->num_b->next;
	}
	return (1);
}

int init_swap(t_swap *data, char **argv, int argc)
{
    data->arg = malloc_list(data, sizeof(t_arg));
	data->arg->num_a = NULL;
	data->arg->num_b = NULL;
    if (!data->arg)
	{
        return (ERR_MALLOC);
	}
	data->arg->nb = argc;
	data->error = 0;
    return (parser_nb(data, argv));
}