/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:07:08 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 01:09:20 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		one;
	size_t		two;

	if (!s1 || !s2)
		return (0);
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, one + 1);
	ft_strlcat(str + one, s2, two + 1);
	return (str);
}
