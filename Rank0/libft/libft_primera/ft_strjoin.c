/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:25:05 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/23 19:36:28 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*joint;

	i = 0;
	joint = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint)
	{
		free (joint);
		return (0);
	}
	while (i < ft_strlen(s1))
	{
		joint[i] = s1[i];
		++i;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		joint[i] = s2[i - ft_strlen(s1)];
		++i;
	}
	joint[i] = 0;
	return (joint);
}
/*
int main(int argc, char *argv[])
{
char separador[] = ",xxx,";
char *resultado;
printf("argc: %d\n",argc);
int tamano = argc -1;

resultado = ft_strjoin(tamano, argv, separador);

printf("%s",resultado);	
}*/