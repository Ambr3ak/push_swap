/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:09:33 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:09:36 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	sort_min(t_swap *data)
{
	t_list_int	*a_tmp;

	a_tmp = data->a->next;
	if (data->a->content > a_tmp->content)
		sa(&data->a);
}

void	init_tab(t_list_int *list, int *tab, int size)
{
	int			i;
	t_list_int	*lst;

	lst = list;
	i = 0;
	while (i < size)
	{
		tab[i] = (int)lst->content;
		lst = lst->next;
		i++;
	}
}

void	sort_three(t_swap *data)
{
	init_tab(data->a, data->tab, 3);
	if (data->tab[0] > data->tab[1] && data->tab[1] > data->tab[2])
	{
		sa(&data->a);
		rra(&data->a);
	}
	else if (data->tab[0] < data->tab[1] && data->tab[1] > data->tab[2])
	{
		if (data->tab[0] > data->tab[2])
			rra(&data->a);
		else
		{
			sa(&data->a);
			ra(&data->a);
		}
	}
	else if (data->tab[0] > data->tab[1] && data->tab[1] < data->tab[2])
	{
		if (data->tab[0] < data->tab[2])
			sa(&data->a);
		else
			ra(&data->a);
	}
}

void	sort_10(t_swap *data)
{
	int	smaller;

	while (get_lst_size(data->a) != 3)
	{
		smaller = small(data->a);
		data->index = get_index(data->a, smaller);
		if (get_lst_size(data->a) / 2 > data->index)
			ra(&data->a);
		else
			rra(&data->a);
		if (data->a->content == smaller)
			pb(&data->a, &data->b);
	}
	sort_three(data);
	while (data->b)
		pa(&data->a, &data->b);
}
