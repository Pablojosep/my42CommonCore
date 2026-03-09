/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:20 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/22 09:47:54 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int resultado;
	unsigned int b = 2;
	char esse1[]="pablo";
	char esse2[]="";
	resultado = ft_strncmp(esse1,esse2,b);
	printf("\n resultado :%d\n",resultado);
	printf("\n esse1 :%s\n",esse1);
	printf("\n esse2 :%s\n",esse2);
	resultado = strncmp(esse1,esse2,b);
	printf("\n resultado :%d\n",resultado);
	printf("\n esse1 :%s\n",esse1);
	printf("\n esse2 :%s\n",esse2);
}*/
