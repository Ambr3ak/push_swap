/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:04 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:10:11 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	lst_add(int ptr, t_list_int **stack)
{
	t_list_int	*elem;

	elem = ft_lstnew_int(ptr);
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
	int	i;

	i = 0;
	while (i < data->lst_size)
	{
		lst_add(tmp[i], stack);
		i++;
	}
	if (!is_sorted(data->a, tmp, data->lst_size))
		return (0);
	return (ERR_DOUBLE);
}

int	init_swap(t_swap *data, char **argv, int argc)
{
	data->tab = malloc_list(data, sizeof(int) * 3);
	data->tmp = malloc_list(data, sizeof(int) * argc);
	data->smallst = -1;
	data->j = 0;
	if (!data->tab)
	{
		return (ERR_MALLOC);
	}
	data->nb_ac = argc;
	data->lst_size = argc - 1;
	data->error = 0;
	return (parser_nb(data, argv));
}

t_list_int	*init_k(t_list_int *list_a)
{
	t_list_int	*lst;
	t_list_int	*tmp_k;

	lst = list_a;
	tmp_k = NULL;
	while (lst)
	{
		lst_add(lst->content, &tmp_k);
		lst = lst->next;
	}
	return (tmp_k);
}
