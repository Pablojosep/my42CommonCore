/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:49:17 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/15 19:05:09 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}
/*
int main(void)
{
	int letra;

	letra = '8';
	printf("%c original y cambia a: %c\n",letra,ft_toupper(letra));
	return (0);
}*/
