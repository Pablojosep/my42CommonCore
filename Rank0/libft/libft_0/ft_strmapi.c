/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:58:45 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/25 09:29:38 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
	{
		free (copy);
		return (0);
	}
	while (i < ft_strlen(s))
	{
		copy[i] = (*f)(i, s[i]);
		++i;
	}
	copy[i] = 0;
	return (copy);
}
