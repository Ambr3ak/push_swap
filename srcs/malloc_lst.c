/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:47:05 by abourdar          #+#    #+#             */
/*   Updated: 2021/09/08 22:47:06 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	*lst_add_mlc(t_swap *data, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!(elem))
	{
		free(ptr);
		return (NULL);
	}
	if (!(data->mlc))
		data->mlc = elem;
	else
		ft_lstadd_back(&data->mlc, elem);
	return (ptr);
}

void	*malloc_list(t_swap *data, int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (!lst_add_mlc(data, ptr))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

void	*free_malloc_lst(t_swap *data)
{
	ft_lstclear(&data->mlc, free);
	return (0);
}
