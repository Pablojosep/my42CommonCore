/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:36:59 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/23 10:32:39 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	k;

	dest_size = 0;
	src_size = 0;
	k = 0;
	while (dest[dest_size] != '\0')
		++dest_size;
	while (src[src_size] != '\0')
		++src_size;
	while (size > k && src[k] != '0')
	{
		dest[dest_size + k] = src[k];
		++k;
	}
	dest[dest_size + k - 1] = '\0';
	if (size < src_size)
		return (dest_size + size - 2);
	else
		return (dest_size + src_size); 
}
/*
int main(void)
{
	char fuente[]="y este es el fin";   //16
	char destino[50]="este es el inicio,"; //18
	char fuente2[]="y este es el fin";
	char destino2[50]="este es el inicio,";
	unsigned int tamano=5;
	unsigned int d;
	unsigned int e;
	

	d=ft_strlcat(destino,fuente,tamano);
	printf("\nvalor con la funcion copia: %d\n",d);
	printf("\n%s\n",destino);

	e=strlcat(destino2,fuente2,tamano);
	printf("\nvalor con la funcion original: %d\n",e);
	printf("\n%s\n",destino2);
}*/
