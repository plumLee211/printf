/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:08:04 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/28 22:37:43 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long long n)
{
	size_t				i;

	i = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	exe_itoa(unsigned int n, char *str, int len)
{
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char				*str;
	int					len;
	unsigned int		x;

	len = ft_len(n);
	if (n < 0)
	{
		x = -1 * n;
		len += 1;
	}
	else
		x = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	len -= 1;
	if (n < 0)
		str[0] = '-';
	exe_itoa(x, str, len);
	return (str);
}
