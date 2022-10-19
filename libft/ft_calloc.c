/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:06:00 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/22 01:06:59 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t bytes)
{
	void	*str;

	str = malloc(n * bytes);
	if (str == 0)
		return (0);
	ft_bzero(str, n * bytes);
	return (str);
}
