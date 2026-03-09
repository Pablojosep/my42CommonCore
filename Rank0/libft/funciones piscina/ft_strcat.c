/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:08:41 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/23 10:42:52 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*dest != '\0')
	{
		++dest;
		i++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		i++;
	}
	*dest = '\0';
	return (dest - i);
}
/*
int	main(void)
{
	char *resultado;
	char *resultado2;
	
	char fuente[]=" fuente muy chevere";
	char destino[]="destino";
	char fuente2[]=" fuente muy chevere";
	char destino2[]="destino";
	
	resultado=ft_strcat(destino,fuente);
	printf("\n%s\n",resultado);
		
	resultado2=strcat(destino2,fuente2);
	printf("\n%s\n",resultado2);
}*/