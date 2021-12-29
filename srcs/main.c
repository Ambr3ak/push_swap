#include "../inc/push.h"

void exit_prog(t_swap *data, int error)
{
	if (error == -1)
		ft_putstr_fd("Error\nBad arguments", 1);
	if (error == -2)
		ft_putstr_fd("Error\nNot only integers", 1);
	if (error == -3)
		ft_putstr_fd("Error\nInteger is more than 1 time", 1);
	//if (error == 0)
	//	ft_putstr_fd("Ok\n", 1);
	free_malloc_lst(data);
	free(data);
	exit (0);
}

int main(int argc, char **argv)
{
    t_swap *data;

    if (argc < 2)
    {
		ft_putstr_fd("Error\nbad num_aber of arguments", 1);
	    return(-1);
	}
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
