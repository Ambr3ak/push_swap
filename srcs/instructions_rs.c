/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:10:51 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:10:53 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	rr(t_list_int **list_a, t_list_int **list_b)
{
	ra(list_a);
	rb(list_b);
}

void	ss(t_list_int **list_a, t_list_int **list_b)
{
	sa(list_a);
	sb(list_b);
}

void	rrr(t_list_int **list_a, t_list_int **list_b)
{
	rra(list_a);
	rrb(list_b);
}
