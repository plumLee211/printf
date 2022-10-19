/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:42:54 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 00:55:57 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	len;
	size_t	i;

	if (!dest || !src)
		return (0);
	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (dsize != 0)
	{
		while (src[i] != '\0' && i + 1 < dsize)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (len);
}
