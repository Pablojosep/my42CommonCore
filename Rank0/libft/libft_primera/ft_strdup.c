/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:48:10 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 14:50:51 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		++i;
	copy = (char *) malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		++i;
	}
	copy[i] = 0;
	return ((char *)copy);
}
/*
int	main(void)
{
	char cadena[] = "de aqui se copia el mensaje";
	printf("%s",ft_strdup(cadena));
}*/
