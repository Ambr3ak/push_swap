/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:22:05 by abourdar          #+#    #+#             */
/*   Updated: 2020/11/27 17:42:03 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*list;

	list = lst;
	if (lst)
	{
		lst = lst->next;
		(*del)(list->content);
		free(list);
	}
}

void	ft_lstdelone_int(t_list_int *lst, void (*del)(int))
{
	t_list_int	*list;

	list = lst;
	if (lst)
	{
		lst = lst->next;
		(*del)(list->content);
		free(list);
	}
}