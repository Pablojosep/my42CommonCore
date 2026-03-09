/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:58:09 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 18:36:48 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizeofnumber(int numbero)
{
	int	counting;

	counting = 0;
	if (numbero == 0)
		return (1);
	while (numbero != 0)
	{
		numbero = numbero / 10;
		++counting;
	}
	return (counting);
}

int	ft_absofnumber(int negative)
{
	if (negative < 0)
		negative = -1 * negative;
	return (negative);
}

int	ft_copynumberitoa(char *number)
{
	if (!number)
	{
		free (number);
		return (0);
	}
	return (1);
}

char	*ft_itoa(int n)
{
	int		count;
	int		neg;
	char	*number;

	count = 0;
	neg = 1;
	if (n < 0)
	{
		neg = neg * -1;
		++count;
	}
	count = count + ft_sizeofnumber(n);
	number = (char *)malloc((sizeof(char)) * (count + 1));
	if (ft_copynumberitoa(number) == 0)
		return (0);
	number[count] = 0;
	while (count > 0)
	{
		--count;
		number[count] = 48 + ft_absofnumber(n % 10);
		n = n / 10;
	}
	if (neg == -1)
		number[0] = '-';
	return (number);
}

/*char	*ft_itoa(int n)
{
	int		count;
	int		neg;
	char	*number;

	count = 0;
	neg = 1;
	if (n < 0)
	{
		neg = neg * -1;
		++count;
	}
	count = count + ft_sizeofnumber(n);
	number = (char *)malloc((sizeof(char)) * (count + 1));
	if (!number)
	{
		free (number);
		return (0);
	}
	number[count] = 0;
	while (count > 0)
	{
		--count;
		number[count] = 48 + ft_absofnumber(n % 10);
		n = n / 10;
	}
	if (neg == -1)
		number[0] = '-';
	return (number);
}*/
