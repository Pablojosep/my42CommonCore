/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:54:31 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/21 21:11:38 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	comp;
	int	i;

	comp = 0;
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		++i;
	comp = s1[i] - s2[i];
	return (comp);
}
/*
int	main(void)
{
	int resultado;
	char esse1[]="pabl";
	char esse2[]="pabm";
	resultado = ft_strcmp(esse1,esse2);
	printf("\n resultado :%d\n",resultado);
}*/
