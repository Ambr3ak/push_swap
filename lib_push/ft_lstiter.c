/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:20:11 by abourdar          #+#    #+#             */
/*   Updated: 2020/11/27 17:42:17 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *list;

	list = lst;
	if (list)
		while (list)
		{
			(*f)(list->content);
			list = list->next;
		}
	else
		return ;
}
