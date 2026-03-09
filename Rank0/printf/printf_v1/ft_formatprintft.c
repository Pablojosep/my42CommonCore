/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatprintft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:03:34 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/20 12:58:04 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_p(unsigned long long int address)
{
	char	*base;

	base = "0123456789abcdef";
	if (address == 0)
		return (ft_putstrprint("(nil)"));
	else
		return (ft_putstrprint("0x") + ft_format_p_print(address, base));
}

int	ft_format_p_print(unsigned long long int nbr, char *base)
{
	char			*impresion;
	long long int	store;
	int				quotient;
	long long int	buffer;
	int				i;

	i = 0;
	impresion = (char *)malloc(sizeof(char *) * (ft_printlgt(nbr) + 1));
	if (!impresion)
		free(impresion);
	store = nbr / 16;
	quotient = nbr % 16;
	while (store != 0 || quotient != 0)
	{
		impresion[i] = base[quotient];
		buffer = store;
		store = store / 16;
		quotient = buffer % 16;
		++i;
	}
	if (i != 0)
		impresion[i + 1] = base[buffer];
	return (ft_printing_final(i, nbr, impresion));
}

int	ft_format_x(const char string, long int number)
{
	if (number < 0)
		number = 0xffffffff + number + 1;
	if (string == 'x')
		return (ft_putnbr_base(number, "0123456789abcdef"));
	else
		return (ft_putnbr_base(number, "0123456789ABCDEF"));
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	int	elementsinbase;

	elementsinbase = 0;
	while (base[elementsinbase] != '\0')
		++elementsinbase;
	if (nbr == 0)
	{
		write(1, base, 1);
		return (1);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
		return (ft_printing(nbr, elementsinbase, base) + 1);
	}
	return (ft_printing(nbr, elementsinbase, base));
}

int	ft_putstrprint(char *s)
{
	int	i;

	i = 0;
	if (!s)
		i = ft_putstrprint("(null)");
	else
	{
		while (s[i] != '\0')
			write(1, &s[i++], 1);
	}
	return (i);
}
