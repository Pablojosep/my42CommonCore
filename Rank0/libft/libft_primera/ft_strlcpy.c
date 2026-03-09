/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:49:14 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/20 11:02:55 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1 && size != 0)
		{
			dst[i] = ((char *)src)[i];
			++i;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		++i;
	return (i);
}
/*
int	main(void)
{
	char destino[] = "esta es una frase";
	const char fuente[] = "borrador";

	printf("resultado = %zu,",ft_strlcpy(destino,fuente,5));
	printf(" %s", destino);
	return (0);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && src[i] != '\0' && i < size - 1)
	{
		dst[i] = ((char *)src)[i];
		++i;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		++i;
	return (i);
}*/
