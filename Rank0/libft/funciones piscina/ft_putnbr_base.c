/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:27:29 by ppenuela          #+#    #+#             */
/*   Updated: 2023/12/29 13:15:37 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_ft(int i, int nb, char *impresion)
{
	while (i + 1 > 0 && nb != 0)
	{
		write(1, &impresion[i - 1], 1);
		--i;
	}
}

void	ft_printing(int nbr, int elementos_en_cadena, char *base)
{
	char	impresion[100];
	int		almacen;
	int		cociente;
	int		buffer;
	int		i;

	i = 0;
	if (nbr == 0)
		write(1, base, 1);
	else
	{
		almacen = nbr / elementos_en_cadena;
		cociente = nbr % elementos_en_cadena; 
		while (almacen != 0 || cociente != 0)
		{
			impresion[i] = base[cociente];
			buffer = almacen;
			almacen = almacen / elementos_en_cadena;
			cociente = buffer % elementos_en_cadena;
			++i;
		}
		if (i != 0)
			impresion[i + 1] = base[buffer];
	}
	print_ft(i, nbr, impresion);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	elementos_en_cadena;

	elementos_en_cadena = 0;
	while (base[elementos_en_cadena] != '\0')
		++elementos_en_cadena;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	ft_printing(nbr, elementos_en_cadena, base);
}
/*
#include <limits.h>

int	main(void)
{
	char base_a_usar[16] = "0123456789ABCDEF";
	ft_putnbr_base(0, base_a_usar);
	write(1, "\n", 1);
	ft_putnbr_base(INT_MIN, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(INT_MAX, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(0, "01234567890");
	write(1, "\n", 1);
	ft_putnbr_base(0, "01234567 89");
	write(1, "\n", 1);
	ft_putnbr_base(0, "012345678-9");
	write(1, "\n", 1);
	ft_putnbr_base(0, "01234567+89");
	write(1, "\n", 1);
	ft_putnbr_base(0, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(0, "]a1*");
	write(1, "\n", 1);
}*/
