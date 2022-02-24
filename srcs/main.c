/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:59 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:11:00 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	exit_prog(t_swap *data, int error)
{
	if (error != 0 && error != LIST_TRIEE)
		ft_putstr_fd("Error\n", 2);
	ft_lstclear_int(&data->a);
	ft_lstclear_int(&data->k);
	free_malloc_lst(data);
	free(data);
	exit (0);
}

int	check_size(char *argv)
{
	if (ft_strlen(argv) > 11)
		return (-1);
	return (0);
}

int	two_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ' || (!ft_isdigit(argv[i]) && argv[i] != '-'))
			return (-1);
		i++;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_swap	*data;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		if (!two_argv(argv[1]))
			return (0);
	data = malloc(sizeof(t_swap));
	ft_memset(data, 0, sizeof(t_swap));
	if (data)
	{
		data->mlc = NULL;
		data->error = init_swap(data, argv, argc);
		if (!data->error)
			start_sort(data);
	}
	exit_prog(data, data->error);
}
