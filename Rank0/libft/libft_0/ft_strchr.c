/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:05:35 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 14:47:05 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	car;

	car = (unsigned char)c;
	i = 0;
	if (car == 0)
		return ((char *)(s + (int)ft_strlen(s)));
	while ((unsigned char)s[i] != car && s[i] != '\0')
		++i;
	if (s[i] == '\0')
		return ((char *) NULL);
	return ((char *)(s + i));
}
/*
int main(void)
{
	const char palabraUno[] = "Destino";
	char parametro;
	char *palabraDos;
	parametro = 'p';
	palabraDos = ft_strchr(palabraUno, parametro);
	printf("%s",palabraDos);
	return (0);
}
*/

/*char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	car;

	car = (unsigned char)c;
	i = 0;
	if (!s)
		return ((char *)s);
	if (car == 0)
		return ((char *)(s + (int)ft_strlen(s)));
	while ((unsigned char)s[i] != car && s[i] != '\0')
		++i;
	if (s[i] == '\0')
		return ((char *) NULL);
	return ((char *)(s + i));
}*/
