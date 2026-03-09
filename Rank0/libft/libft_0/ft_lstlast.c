/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:37:57 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 10:22:19 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*copy;

	i = 0;
	copy = ft_lstnew(0);
	copy = lst;
	if (!lst)
		return (0);
	while (copy != NULL)
	{
		copy = copy->next;
		i++;
	}
	while (i-- > 1)
		lst = lst->next;
	return (lst);
}*/
