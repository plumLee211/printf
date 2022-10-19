/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:39:27 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/31 19:22:41 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	unsigned char	ch;
	char			*arr;
	size_t			i;
	size_t			len;

	len = ft_strlen(str);
	ch = (unsigned char)n;
	arr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			arr = (char *)&str[i];
		i++;
	}
	if (ch == 0)
		return ((char *)&str[len]);
	return (arr);
}
