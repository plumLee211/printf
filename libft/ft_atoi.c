/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/22 01:24:50 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char x)
{
	if (x == ' ' || x == '\n' || x == '\t'
		|| x == '\f' || x == '\r' || x == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] != '\0') && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (sign * num);
}
