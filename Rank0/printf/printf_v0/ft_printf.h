/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:52:51 by miamachine        #+#    #+#             */
/*   Updated: 2024/07/19 19:16:42 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_format_p(unsigned long long int address);
int		ft_format_x(const char string, long int number);
int		ft_putnbr_base(long long int nbr, char *base);
int		ft_printing_final(int i, long int nb, char *impresion);
int		ft_printlgt(unsigned long long int numbero);
int		ft_printing(long long int nbr, int elementos_en_cadena, char *base);
int		ft_printformat(const char *string, int i, va_list args);
int		ft_printf(const char *string, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_format_p_print(unsigned long long int nbr, char *base);

#endif