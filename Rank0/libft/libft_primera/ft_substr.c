/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:34:58 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/23 19:23:22 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	copy = (char *)malloc((sizeof(char) * len) + 1);
	if (!copy)
	{
		free (copy);
		return (0);
	}
	copy[i] = 0;
	while (i < len)
	{
		copy[i] = s[start + i];
		++i;
	}
	copy[i] = 0;
	return (copy);
}
