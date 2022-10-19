/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:40:20 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/28 22:38:37 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = dest;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)val;
		i++;
	}
	return (dest);
}
