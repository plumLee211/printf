/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:42:52 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/18 01:39:09 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*now;

	now = *lst;
	if (!lst || !new)
		return ;
	if ((*lst) == 0)
	{
		(*lst) = new;
		return ;
	}
	else
	{
		now = *lst;
		while (now->next)
			now = now->next;
		now->next = new;
	}
}
