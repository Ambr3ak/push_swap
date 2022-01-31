#include "../inc/push.h"

void exit_prog(t_swap *data, int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nBad arguments", 1);
	if (error == -2)
		ft_putstr_fd("Error\nNot only integers", 1);
	if (error == -3)
		ft_putstr_fd("Error\nInteger is more than 1 time", 1);
	ft_lstclear_int(&data->a);
    ft_lstclear_int(&data->arg->stack_k);
	free_malloc_lst(data);
	free(data);
	exit (0);
}

int two_argv(char argv[1])
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (-1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    t_swap *data;

    if (argc < 2)
    {
		ft_putstr_fd("Error\nbad number of arguments", 1);
	    return(-1);
	}
	else if (argc == 2)
		if (!two_argv(argv[1]))
			return (0);
    data = malloc(sizeof(t_swap));
    data->mlc = NULL;
    if (data)
	{
        data->error = init_swap(data, argv, argc);
		if (!data->error)
			start_sort(data);
	}
    exit_prog(data, data->error);
}
