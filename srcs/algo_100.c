/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:08:50 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:08:56 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	sort_a_2(t_swap *data)
{
	int			count;
	t_list_int	*tmp_b;
	int			index;
	int			lrg;

	count = 0;
	while (data->b)
	{
		tmp_b = data->b->next;
		lrg = large(data->b);
		if (data->b->content != lrg && tmp_b->content == lrg)
			sb(&data->b);
		index = get_index(data->b, lrg);
		if (index == 0)
			pa(&data->a, &data->b);
		else if ((get_lst_size(data->b)) / 2 > index)
			rb(&data->b);
		else
			rrb(&data->b);
	}
}

void	sort_a(t_swap *data)
{
	int	smaller;

	while (get_lst_size(data->a) > 1)
	{
		smaller = small(data->a);
		data->index = get_index(data->a, smaller);
		proximity_algo(data, data->index);
	}
}

void	sort_100(t_swap *data)
{
	int			key_nbr;
	t_list_int	*lst;
	int			idx;
	int			size;

	data->k = init_k(data->a);
	sort_k(data);
	lst = data->k;
	size = get_lst_size(data->k);
	idx = size / 4;
	while (idx < size)
	{
		key_nbr = find_chunk(data->k, idx);
		while (find_keynbr(data, data->a, key_nbr))
		{
			data->index = get_index(data->a, data->key_nbr);
			proximity_algo(data, data->index);
		}
		idx += size / 4;
	}
	sort_a(data);
	sort_a_2(data);
}
