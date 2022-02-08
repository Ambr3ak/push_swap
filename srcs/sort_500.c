/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:35 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:11:37 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	sort_more(t_swap *data)
{
	int			key_nbr;
	t_list_int	*lst;
	int			idx;
	int			size;

	data->k = init_k(data->a);
	sort_k(data);
	lst = data->k;
	size = get_lst_size(data->k);
	idx = size / 11;
	while (idx < size)
	{
		key_nbr = find_chunk(data->k, idx);
		while (find_keynbr(data, data->a, key_nbr))
		{
			data->index = get_index(data->a, data->key_nbr);
			proximity_algo(data, data->index);
		}
		idx += size / 11;
	}
	sort_a(data);
	sort_a_2(data);
}
