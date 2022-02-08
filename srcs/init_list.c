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
	return (LIST_TRIEE);
}

int	init_swap(t_swap *data, char **argv, int argc)
{
	data->arg = malloc_list(data, sizeof(t_arg));
	data->a = NULL;
	data->b = NULL;
	data->k = NULL;
	data->smallst = -1;
	data->j = 0;
	if (!data->arg)
	{
		return (ERR_MALLOC);
	}
	data->arg->nb = argc;
	data->lst_size = argc - 1;
	data->error = 0;
	return (parser_nb(data, argv));
}

void	init_tab(t_list_int *list, int *tab)
{
	int			i;
	t_list_int	*lst;

	lst = list;
	i = 0;
	while (lst)
	{
		tab[i] = (int)lst->content;
		lst = lst->next;
		i++;
	}
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
