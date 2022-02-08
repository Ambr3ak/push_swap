/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:54 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:11:55 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	ra_k(t_list_int **list_a)
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *list_a;
	if (list && list->next)
	{
		tmp = list;
		list = list->next;
		ft_lstadd_back_int(list_a, tmp);
		tmp->next = NULL;
		*list_a = list;
	}
}

void	rra_k(t_list_int **list_a)
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *list_a;
	if (list && list->next)
	{
		tmp = list;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front_int(list_a, tmp->next);
		tmp->next = NULL;
	}
}

void	pa_k(t_list_int **a, t_list_int **b)
{
	t_list_int	*tmp;
	t_list_int	*list_b;

	list_b = *b;
	if (list_b)
	{
		tmp = list_b;
		list_b = list_b->next;
		ft_lstadd_front_int(a, tmp);
		*b = list_b;
	}
}

void	pb_k(t_list_int **a, t_list_int **b)
{
	t_list_int	*tmp;
	t_list_int	*list_a;

	list_a = *a;
	if (list_a)
	{
		tmp = list_a;
		list_a = list_a->next;
		ft_lstadd_front_int(b, tmp);
		*a = list_a;
	}
}

void	sort_k(t_swap *data)
{
	t_list_int	*k_b;

	k_b = NULL;
	while (get_lst_size(data->k) != 1)
	{
		data->index = get_index(data->k, find_small(data, data->k));
		if (get_lst_size(data->k) / 2 > data->index)
			ra_k(&data->k);
		else
			rra_k(&data->k);
		if (data->k->content == data->smallst)
			pb_k(&data->k, &k_b);
	}
	while (k_b)
		pa_k(&data->k, &k_b);
}
