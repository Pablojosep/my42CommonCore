/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:27:23 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 19:07:01 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dest;
	char	*p_src;
	size_t	i;

	p_dest = (char *)dest;
	p_src = (char *)src;
	i = 0;
	if ((p_dest < p_src) && (dest || src))
	{
		while (i < n)
		{
			p_dest[i] = p_src[i];
			++i;
		}
	}
	else if (!(p_dest < p_src) && (dest || src))
	{
		while (i < n)
		{
			p_dest[n - i -1] = p_src[n - i -1];
			++i;
		}
	}
	return (dest);
}
