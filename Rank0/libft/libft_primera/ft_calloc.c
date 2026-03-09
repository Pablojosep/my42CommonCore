/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:42:56 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/26 20:56:21 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer_calloc;
	size_t	i;

	i = 0;
	pointer_calloc = (char *) malloc((size * nmemb));
	if (!pointer_calloc)
		return (0);
	while (i <= size * nmemb)
	{
		pointer_calloc[i] = '\0';
		++i;
	}
	return ((void *)pointer_calloc);
}
