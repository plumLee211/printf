/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:07:26 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/31 16:41:12 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(const char *s1, const char *set)
{
	int			len;
	int			i;

	len = (int)(ft_strlen(s1));
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_end(const char *s1, const char *set)
{
	int			len;
	int			i;

	len = (int)(ft_strlen(s1));
	i = len - 1;
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			st;
	int			ed;
	char		*str;

	if (!s1 || !set)
		return (0);
	str = 0;
	st = ft_start(s1, set);
	ed = ft_end(s1, set);
	if (st == -1 || ed == -1)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (ed - st + 2));
	if (!str)
		return (0);
	i = 0;
	while (st <= ed)
		str[i++] = s1[st++];
	str[i] = '\0';
	return (str);
}
