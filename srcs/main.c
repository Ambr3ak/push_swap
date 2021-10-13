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

void	*lst_add(t_arg *arg, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!(elem))
	{
		free(ptr);
		return (NULL);
	}
	if (!(arg->num))
		arg->num = elem;
	else
		ft_lstadd_back(&arg->num, elem);
	return (ptr);
}

void	*init_lst(t_arg *arg, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		
		if (!lst_add(arg, argv[i]))
			return (NULL);
			arg->num->content = (void *)1;
		printf("%d\n", (int)arg->num->content);
		i++;
	}
	return (arg);
}


int parser_nb(t_swap *data, char **argv)
{
    int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]) && argv[i][j])
			j++;
		if (argv[i][j] != '\0')
			return (ERR_ARG);
		i++;
	}
	if (!init_lst(data->arg, argv))
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