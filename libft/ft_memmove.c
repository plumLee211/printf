/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:41:37 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/31 19:02:55 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s == d)
		return (d);
	i = 0;
	if (d < s)
		while (i++ < n)
			d[i] = s[i];
	else
		while (i++ < n)
			d[n - 1 - i] = s[n - 1 - i];
	return (d);
}
