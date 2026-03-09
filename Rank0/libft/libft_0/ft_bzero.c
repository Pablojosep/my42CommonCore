/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:57:38 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/14 13:03:53 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*copy;
	size_t				i;

	copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		copy[i] = '\0';
		++i;
	}
}
