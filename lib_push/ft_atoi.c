/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:51:21 by abourdar          #+#    #+#             */
/*   Updated: 2020/11/30 10:13:45 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

int	ft_atoi(const char *str)
{
	int			m;
	long		res;
	char		*strr;

	m = 0;
	res = 0;
	strr = (char *)str;
	while (*strr == ' ' || (*strr > 8 && *strr < 14))
		strr++;
	if (*strr == '-' || *strr == '+')
	{
		if (*strr == '-')
			m++;
		strr++;
	}
	while (*strr >= '0' && *strr <= '9')
	{
		res = res * 10 + *strr - '0';
		strr++;
	}
	if (m % 2 != 0)
		res = -res;
	return (res);
}
