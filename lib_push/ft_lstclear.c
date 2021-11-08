/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:38:43 by abourdar          #+#    #+#             */
/*   Updated: 2020/11/27 17:39:52 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		(*del)(list->content);
		free(list);
		list = tmp;
	}
	*lst = NULL;
}

void	ft_lstclear_int(t_list_int **lst, void (*del)(int))
{
	t_list_int	*tmp;
	t_list_int	*list;

	list = *lst;
	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		(*del)(list->content);
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
