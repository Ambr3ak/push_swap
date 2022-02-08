/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:07 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:11:08 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	check_double(int *tmp, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (tmp[i])
	{
		j = i + 1;
		if (j == nb - 1)
			break ;
		while (tmp[j] && j < nb - 1)
		{
			if (tmp[i] == tmp[j])
				return (ERR_DOUBLE);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_atoi(t_swap *data, char **argv)
{
	int	i;
	int	j;
	int	*tmp;

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
	if (check_double(tmp, data->arg->nb) < 0)
		return (ERR_DOUBLE);
	return (init_lst(data, tmp, &data->a));
}

int	check_int(t_swap *data, char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			return (ERR_INT);
		i++;
	}
	return (init_atoi(data, argv));
}

int	parser_nb(t_swap *data, char **argv)
{
	int	i;
	int	j;
	int	l;

	i = 1;
	l = 0;
	while (argv[i])
	{
		j = 0;
		while ((ft_isdigit(argv[i][j]) || argv[i][0] == '-'
				|| argv[i][0] == '+') && argv[i][j])
		{
			j++;
		}
		if (argv[i][j] != '\0' || (argv[i][j] == '\0' && j == 0))
			return (ERR_ARG);
		l++;
		i++;
	}
	return (check_int(data, argv));
}
