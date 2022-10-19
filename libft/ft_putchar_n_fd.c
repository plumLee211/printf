/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:53:09 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/12/28 18:53:49 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_n_fd(char c, int fd, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += (int)write(fd, &c, 1);
	return (count);
}
