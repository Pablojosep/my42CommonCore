/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:24:11 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/31 20:50:43 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*joint;

	i = 0;
	joint = (char *)malloc(sizeof(char *) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joint)
	{
		free (joint);
		return (0);
	}
	while (i < ft_strlen(s1))
	{
		joint[i] = s1[i];
		++i;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		joint[i] = s2[i - ft_strlen(s1)];
		++i;
	}
	joint[i] = 0;
	return (joint);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		++i;
	copy = (char *) malloc(sizeof(char) * (i + 1));
	if (!copy)
	{
		free (copy);
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		++i;
	}
	copy[i] = 0;
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
		s++;
	if (*s == c)
		return ((char *) s);
	return ((char *) NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return (dst);
}
