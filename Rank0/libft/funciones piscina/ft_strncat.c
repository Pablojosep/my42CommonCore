/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:19:36 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/23 10:39:24 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i] != '\0')
		++i;
	if (nb > i)
		nb = i;
	while (dest[j] != '\0')
		++j;
	while (k < nb)
	{
		dest[j + k] = src[k];
		++k;
	}
	dest[j + k] = '\0';
	return (dest);
}
/*
int	main(void)
{
	unsigned int numero;
	char destino[] ="palabra";
	char fuente[]="contenido";
	int resultado;

	numero = 2;
	resultado = *ft_strncat(destino,fuente,numero);
	printf("%s",destino);
}*/
