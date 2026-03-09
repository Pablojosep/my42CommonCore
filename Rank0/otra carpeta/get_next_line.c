/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:38:40 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/27 14:09:04 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_bufferhandler(char *string)
{
	char		*temp;
	size_t		i;
	int			k;

	i = 0;
	k = 0;
	while (string[i] != '\n')
		++i;
	if (ft_strlen(string) - 1 == i)
	{
		free(string);
		return ("");
	}
	temp = malloc(sizeof(char *) * (ft_strlen(string) - i));
	++i;
	while (string[i] != '\0')
	{
		temp[k] = string[i];
		++k;
		++i;
	}
	temp[++k] = '\0';
	free (string);
	return (temp);
}

char	*gnl_readingshandler(char *buffer)
{
	char	*string;
	int		i;

	i = 0;
	while (buffer[i] != '\n')
		++i;
	string = malloc (sizeof(char *) * (i + 2));
	i = 0;
	while (buffer[i] != '\n')
	{
		string[i] = buffer[i];
		++i;
	}
	string[i] = '\n';
	string[i + 1] = '\0';
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*readings;
	int			readresult;
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!store)
		store = "";
	readings = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readings[BUFFER_SIZE] = '\0';
	readresult = read(fd, readings, BUFFER_SIZE);
	if (readresult == 0 && store[0] == '\0')
		return (NULL);
	while (ft_strchr(readings, '\n') == NULL && readresult != 0)
	{
		store = ft_strjoin(store, readings);
		//free(readings);
		//readings = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		//readings[BUFFER_SIZE] = '\0';
		readresult = read(fd, readings, BUFFER_SIZE);
	}
	store = ft_strjoin(store, readings);
	result = gnl_readingshandler(store);
	store = gnl_bufferhandler(store);
	free (readings);
	return (result);
}
