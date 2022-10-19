/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:44:14 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/28 22:37:09 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		str_len;
	size_t		tar_len;
	size_t		i;

	tar_len = ft_strlen(needle);
	str_len = ft_strlen(haystack);
	if (tar_len == 0)
		return ((char *)haystack);
	if (str_len < tar_len || len < tar_len || len == 0)
		return (0);
	i = 0;
	while (haystack[i] != '\0' && i + tar_len <= len)
	{
		if (ft_memcmp(&haystack[i], needle, tar_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
