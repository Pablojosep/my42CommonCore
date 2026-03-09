/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:55:59 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 14:29:02 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (((unsigned char *)s)[i] == 0 && n == 0)
		return (0);
	if (((unsigned char *)s)[i] == '\0' && (unsigned char)c == 0)
		return ((void *)(s + i));
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		++i;
	}
	return (0);
}
/*void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (((const char *)s)[i] != '\0' && i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			while (i-- > 0)
				++s;
			return (((void *)s));
		}
		++i;
	}
	return (0);
}*/
