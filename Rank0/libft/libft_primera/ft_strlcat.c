/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:31:33 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/20 15:01:57 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	j;
	size_t	source_size;

	dst_size = 0;
	j = 0;
	source_size = 0;
	while (src[source_size] != '\0')
		++source_size;
	while (dst[dst_size] != '\0' && size != 0)
		++dst_size;
	if (size != 0)
	{
		while (src[j] != '\0' && dst_size + j < size - 1)
		{
			dst[dst_size + j] = ((char *)src)[j];
			++j;
		}
		dst[dst_size + j] = '\0';
	}
	if (size > dst_size)
		return (dst_size + source_size);
	return (size + source_size);
}
/*size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		++i;
	while (src[j] != '\0' && j < size - i - 1)
	{
		dst[i + j] = ((char *)src)[j];
		++j;
	}
	dst[i + j] = '\0';
	j = 0;
	while (src[j] != '\0')
		++j;
	return (i + j);
}*/
