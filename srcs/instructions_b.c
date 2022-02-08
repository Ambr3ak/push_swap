/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:43 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:10:44 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	sb(t_list_int **list_b)
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *list_b;
	if (list && list->next)
	{
		tmp = list->next;
		list->next = tmp->next;
		ft_lstadd_front_int(list_b, tmp);
	}
	ft_putstr_fd("sb\n", 1);
}

void	rb(t_list_int **list_b)
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *list_b;
	if (list && list->next)
	{
		tmp = list;
		list = list->next;
		ft_lstadd_back_int(list_b, tmp);
		tmp->next = NULL;
		*list_b = list;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rrb(t_list_int **list_b)
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *list_b;
	if (list && list->next)
	{
		tmp = list;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front_int(list_b, tmp->next);
		tmp->next = NULL;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	pb(t_list_int **a, t_list_int **b)
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
		ft_putstr_fd("pb\n", 1);
	}
}
