/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:41:55 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 23:17:13 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int k, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)k)
			return ((unsigned char *)&arr[i]);
		i++;
	}
	return (0);
}
