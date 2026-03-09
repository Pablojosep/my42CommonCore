/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:51:22 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 18:29:13 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nwlist;
	t_list	*temp;
	void	*tempcontent;

	if (!lst || !f || !del)
		return (0);
	nwlist = 0;
	while (lst)
	{
		tempcontent = (*f)(lst->content);
		if (tempcontent)
			temp = ft_lstnew(tempcontent);
		if (!temp || !tempcontent)
		{
			ft_lstclear(&nwlist, del);
			del(tempcontent);
			return (0);
		}
		ft_lstadd_back(&nwlist, temp);
		lst = lst->next;
	}
	return (nwlist);
}
