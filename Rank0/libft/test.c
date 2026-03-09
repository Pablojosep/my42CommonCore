/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:14:09 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 12:00:38 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


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
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc (sizeof(t_list));
	if (!lst)
	{
		free (lst);
		return (0);
	}
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	copy = (t_list *) malloc (sizeof(t_list *));
	if (!copy || !lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	copy = ft_lstlast(*lst);
	copy->next = new;
}

void	ft_del(void *content)
{
	free(content);
}
void	ft_print_result(t_list *elem)
{
	while (elem)
	{
		printf("%s\n",(char *)elem->content);
		elem = elem->next;
	}
}
t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}
void *map_length(void *s)
{
	char *str = malloc(30);
	if (str != NULL)
		sprintf(str, "__%lX", strlen((char *)s));
	return str;
}

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*nwlist;

	nwlist = ft_lstnew(f(lst->content));
	copy = nwlist;
	if (!copy || !lst || !f || !del || !nwlist)
	{	
		free (copy);
		free (nwlist);	
		return (0);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		//copy = ft_lstnew(f(lst->content));
		ft_lstadd_back(&nwlist,ft_lstnew(f(lst->content)));
		if (!nwlist)
		{
			ft_lstclear(&nwlist, del);
			return (0);
		}
	}
	ft_print_result(nwlist);
	ft_print_result(copy);
	return (nwlist);
}

int	main()
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsumi");
	char		*str3 = strdup("doloros");
	char		*str4 = strdup("sitamome");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	


	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	/*while (elem->next)
	{
		printf("%s\n",(char *)elem->content);
		elem = elem->next;
	}*/
	list = ft_lstmap(elem, map_length, ft_del);
	
	int i;
	i = 0;
	
	
	ft_print_result(elem);
	/*
	while (list->next)
	{
		list = list->next;
		ft_print_result(list);
		i++;
	}*/
}