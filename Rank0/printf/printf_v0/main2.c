/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:00:53 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/17 21:56:08 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "limits.h"

int main(void)
{
	//ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	//printf("\n%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");
	/*printf(" %p %p ", ULONG_MAX, -(ULONG_MAX - 1));
	printf("\n");
	printf(" %p %p ", ULONG_MAX, -(ULONG_MAX - 2));
	printf("\n");
	printf(" %p %p ", ULONG_MAX, 0);
	printf("\n");
	printf(" %p %p ", ULONG_MAX, -1);
	printf("\n");
	printf(" %p %p ", ULONG_MAX, -2);
	printf("\n");
	ft_printf(" %p %p ", ULONG_MAX, -2);
	printf("\n");
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n");*/

	//  LONG_MAX 	+9223372036854775807
	//   			7FFF-FFFF-FFFF-FFFF
	// U LONGMAX    18446744073709551615
	//				FFFF-FFFF-FFFF-FFFF
	//              ffff-ffff-ffff-ffff

	/*printf(" %u ", LONG_MAX-1);    	
	printf("\n");
	printf(" %u ", LONG_MAX-2);
	printf("\n");
	printf(" %u ", 4294967296);
	printf("\n");
	printf(" %u ", LONG_MAX+2);
	printf("\n");
	ft_printf(" %u ", LONG_MAX);
	//ft_printf("\nresultado:%d\n",i);
	//j = printf("ORIGI %%%X %%%X", 42, -1);
	//ft_printf("\nresultado:%d\n",j);
	*/
	return 0;
}
