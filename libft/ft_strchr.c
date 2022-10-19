/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:43:35 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/28 22:36:58 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)n)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)n)
		return ((char *)&str[i]);
	return (0);
}
