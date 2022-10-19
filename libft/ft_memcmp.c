/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:42:14 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 22:37:34 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*fir;
	unsigned char	*sec;
	size_t			i;

	if (n == 0)
		return (0);
	fir = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	i = 0;
	while (i != n)
	{
		if (fir[i] != sec[i])
			return ((int)(fir[i] - sec[i]));
		i++;
	}
	return (0);
}
