/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:18:41 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/17 19:31:03 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	numb;

	i = 0;
	neg = 1;
	numb = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\n')
		++i;
	if ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			neg = -1;
		++i;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		numb = numb * 10 + (str[i] - '0');
		++i;
	}
	return (neg * numb);
}
/*
#include <limits.h>

int	main(void)
{
	// int	resultado;
	// char cadena[] = "-2147483647";
	// resultado = ft_atoi(cadena);
	// printf("\n el resulado del numero en la cadena:%d", resultado);
	
	printf("INTMIN: %d\n", ft_atoi(" --+--+2147483648ab567"));
	printf("INTMAX: %d\n", ft_atoi("2147483647"));
	printf("0: %d\n", ft_atoi("0"));
	printf("\"\": %d\n", ft_atoi(""));
	printf("\"-\": %d\n", ft_atoi("-"));
	printf("\"-+\": %d\n", ft_atoi("-+"));
	return (0);
}*/
