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

int	check_double(t_list_int *list)
{
	t_list_int	*list1;
	t_list_int	*list2;

	list1 = list;
	while (list1)
	{
		list2 = list1->next;
		while (list2)
		{
			if (list1->content == list2->content)
				return (ERR_DOUBLE);
			list2 = list2->next;
		}
		list1 = list1->next;
	}
	return (0);
}

int	init_atoi(t_swap *data, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		data->tmp[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (init_lst(data, data->tmp, &data->a) < 0)
		return (LIST_TRIEE);
	return (check_double(data->a));
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
