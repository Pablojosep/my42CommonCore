/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:14:09 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/27 12:27:08 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (!new)
		return;
	copy = ft_lstlast(*lst);
	copy = copy->next;
	copy->content = new->content;
	copy->next = NULL;
}

int	main()
{
	int	fd;
	int nnn = 5454564;
	fd = open("./text.txt", O_RDWR);
	char	*car;
	car = "cambio de frase para experimentar";
	//ft_putendl_fd(car,fd);
	//ft_putstr_fd(car,fd);
	//write(1,&car,1);
	ft_putnbr_fd(nnn,fd);
	return (0);
}