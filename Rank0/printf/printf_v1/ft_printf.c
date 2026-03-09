/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:54:18 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/20 12:59:01 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printing_final(int i, long int nb, char *impresion)
{
	int	count;

	count = i;
	while (i > 0 && nb != 0)
	{
		write(1, &impresion[i - 1], 1);
		--i;
	}
	free(impresion);
	return (count);
}

int	ft_printlgt(unsigned long long int multipliers)
{
	int	counting;

	counting = 0;
	if (multipliers == 0)
		return (1);
	while (multipliers != 0)
	{
		multipliers = multipliers / 10;
		++counting;
	}
	return (counting);
}

int	ft_printing(long long int nbr, int elementsinbase, char *base)
{
	char			*impresion;
	long long int	store;
	int				quotient;
	long long int	buffer;
	int				i;

	impresion = (char *)malloc(sizeof(char *) * (ft_printlgt(nbr) + 1));
	if (!impresion)
		return (0);
	i = 0;
	store = nbr / elementsinbase;
	quotient = nbr % elementsinbase;
	while (store != 0 || quotient != 0)
	{
		impresion[i] = base[quotient];
		buffer = store;
		store = store / elementsinbase;
		quotient = buffer % elementsinbase;
		++i;
	}
	if (i != 0)
		impresion[i + 1] = base[buffer];
	return (ft_printing_final(i, nbr, impresion));
}

int	ft_printformat(const char *string, int i, va_list args)
{
	int		count;

	count = 0;
	if (string[++i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (string[i] == 's')
		count += ft_putstrprint(va_arg(args, char *));
	else if (string[i] == 'p')
		count += ft_format_p(va_arg(args, unsigned long long int));
	else if (string[i] == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned long int) \
		& 0x00000000FFFFFFFF, "0123456789");
	else if (string[i] == 'd' || string[i] == 'i')
		count += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (string[i] == 'x' || string[i] == 'X')
		count += ft_format_x(string[i], va_arg(args, int));
	else if (string[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] != '%')
			count += ft_putchar(string[i]);
		else
			count += ft_printformat(string, i++, args);
		++i;
	}
	va_end (args);
	return (count);
}
