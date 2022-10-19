/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:42:35 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/06/08 20:41:53 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	int			i;

	i = 0;
	*str = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	ft_cnt(char const *s, char c)
{
	int			cnt;
	int			i;

	if (!s)
		return (0);
	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			cnt++;
		else if (i != 0 && s[i - 1] == c && s[i] != c)
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_length(const char *s, char c, int *i)
{
	int			len;

	len = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	return (len);
}

static char	*ft_strndup(const char *str, int n)
{
	char		*arr;
	int			i;

	arr = NULL;
	if (n <= 0)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		arr[i] = str[i];
		i++;
	}
	arr[n] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	int			i;
	int			k;
	int			middlei;

	res = (char **)malloc(sizeof(char *) * (ft_cnt(s, c) + 1));
	if (!s || !res)
		return (0);
	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c || (i != 0 && s[i - 1] == c && s[i] != c))
		{
			middlei = i;
			res[k] = ft_strndup(&s[middlei], ft_length(s, c, &i));
			if (!(res[k]))
				return (ft_free(res));
			k++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	res[k] = 0;
	return (res);
}
