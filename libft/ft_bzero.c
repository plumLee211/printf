/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:40:39 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 22:38:08 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *arr, size_t n)
{
	unsigned char	*arr2;
	size_t			i;

	arr2 = arr;
	i = 0;
	while (i != n)
	{
		arr2[i] = 0;
		i++;
	}
}
