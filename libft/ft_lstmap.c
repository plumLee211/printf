/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:33:39 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/22 01:27:29 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*tem;

	if (lst == 0 || f == 0)
		return (0);
	node = 0;
	while (lst != 0)
	{
		tem = ft_lstnew((*f)(lst->content));
		if (tem == 0)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		ft_lstadd_back(&node, tem);
		tem = tem->next;
		lst = lst->next;
	}
	return (node);
}
