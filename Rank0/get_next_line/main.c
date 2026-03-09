/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:46:04 by ppenuela          #+#    #+#             */
/*   Updated: 2024/08/24 11:07:24 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*#include <unistd.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>*/

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("teste", O_RDONLY);
	//fd = open("teste", O_RDONLY);
	int i = 1;
	fd = -1;
	while((str = get_next_line(fd)))
	{
		printf("%d Linha: %s\n", i++, str);
		free(str);
	}
	
	close(fd);
	
	return (0);
}
