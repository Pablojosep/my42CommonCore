/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:25:10 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/21 10:58:37 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] == '\0' && s2[i] != '\0')
			return (-1);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		if (s1[i] == s2[i])
			++i;
	}
	return (0);
}
/*int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && (s1[i] == '\0' && s2[i] == '\0'))
	{
		if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] == '\0' && s2[i] != '\0')
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] == s2[i])
			++i;
	}
	return (0);
}
*/