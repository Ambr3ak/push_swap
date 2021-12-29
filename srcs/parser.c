#include "../inc/push.h"

int check_double(int *tmp, int nb)
{
	int i;
	int j;

	i = 0;
	j = i + 1;
	while (tmp[i])
	{
		j = i + 1;
		if (j == nb - 2)
				break;
		while (tmp[j] && j < nb - 1)
		{
			if (tmp[i] == tmp[j])
				return (-3);
			j++;
		}
		i++;
	}
	return (0);
}

int init_atoi(t_swap *data, char **argv)
{
	int i;
	int j;
	int *tmp;

	i = 1;
	j = 0;
	tmp = malloc_list(data, sizeof(int) * data->arg->nb);
	if (!tmp)
		return (ERR_MALLOC);
	while (argv[i])
	{
		tmp[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (!check_double(tmp, data->arg->nb))
		return (init_lst(data->arg, tmp, &data->arg->num_a));
	return (-3);
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
		while ((ft_isdigit(argv[i][j]) || argv[i][0] == '-') && argv[i][j])
		{
			j++;
		}
		if (argv[i][j] != '\0')
			return (ERR_ARG);
		l++;
		i++;
	}
	if (init_atoi(data, argv) < 0)
		return (-3);
	return (0);
}