/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:06:41 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/06/11 17:12:16 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
		size_t len)
{
	char			*str;
	size_t			l;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	else
	{
		l = ft_strlen(s + start);
		if (l < len)
			len = l;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, &s[start], len + 1);
	}
	return (str);
}
