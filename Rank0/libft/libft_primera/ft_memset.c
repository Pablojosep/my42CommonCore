/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:49:16 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/14 13:03:32 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*copy;
	long unsigned int	i;

	copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		copy[i] = (unsigned char)c;
		++i;
	}
	return ((void *)copy);
}
