#include "../inc/push.h"

int check_double(char **argv)
{
	int i;
	int j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[i] == argv[j])
				return (ERR_ARG);
			j++;
		}
		i++;
	}
	return (0);
}

int	lst_add(t_arg *arg, int ptr)
{
	t_list_int	*elem;

	elem = ft_lstnew_int((ptr));
	if (!(elem))
	{
		return (ERR_ARG);
	}
	if (!(arg->num))
		arg->num = elem;
	else
		ft_lstadd_back_int(&arg->num, elem);
	return (ptr);
}

t_list_int	*init_lst(t_arg *arg, int *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		
		if (!lst_add(arg, tmp[i]))
			return (NULL);
		i++;
	}
	while (arg->num != NULL)
	{
 		printf("%d -> ", (int)arg->num->content);
        arg->num = arg->num->next;
	}
	return (arg->num);
}

int init_atoi(t_swap *data, char **argv, int l)
{
	int i;
	int j;
	int *tmp;

	i = 1;
	j = 0;
	tmp = malloc_list(data, sizeof(int) * l);
	if (!tmp)
		return (ERR_MALLOC);
	while (argv[i])
	{
		tmp[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (!init_lst(data->arg, tmp))
		return (ERR_LIST);
	return (0);
}

int parser_nb(t_swap *data, char **argv)
{
    int i;
	int j;
	int l;

	i = 1;
	l = 0;
	while (argv[i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]) && argv[i][j])
		{
			j++;
		}
		if (argv[i][j] != '\0')
			return (ERR_ARG);
		else
				l++;
		i++;
	}
	if (!init_atoi(data, argv, l))
		return (ERR_LIST);
	return (0);
}

int init_swap(t_swap *data, char **argv, int argc)
{
    data->arg = malloc_list(data, sizeof(t_arg));
    if (!data->arg)
        return (ERR_MALLOC);
	data->arg->nb = argc;
	data->error = 0;
    return (parser_nb(data, argv));
}

void exit_prog(t_swap *data, int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nBad arguments", 1);
	if (error == 0)
		ft_putstr_fd("Ok", 1);
	free_malloc_lst(data);
	free(data);
	exit (0);
}

int main(int argc, char **argv)
{
    t_swap *data;

    if (argc < 2)
    {
		ft_putstr_fd("Error\nbad number of arguments", 1);
	    return(-1);
	}
    data = malloc(sizeof(t_swap));
    data->mlc = NULL;
    if (data)
        data->error = init_swap(data, argv, argc);
    exit_prog(data, data->error);
}