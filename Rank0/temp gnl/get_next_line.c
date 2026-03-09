/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:38:40 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/31 21:27:53 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*gnl_bufferhandler(char *string)
{
	char		*temp;
	size_t		i;
	int			k;

	i = 0;
	k = 0;
	if (string == NULL || string[0] == '\0')
		return (NULL);
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
		temp[k++] = string[i++];	
	temp[k] = '\0';
	free (string);
	return (temp);
}*/

char	*gnl_bufferhandler(char *string)
{
	char		*temp;
	size_t		i;
	int			k;

	i = 0;
	k = 0;
	if (string == NULL || string[0] == '\0')
		return (NULL);
	while (string[i] != '\n')
		++i;
	if (ft_strlen(string) - 1 == i)
	{
		free(string);
		return (NULL);
	}
	temp = malloc(sizeof(char *) * (ft_strlen(string) - i));
	++i;
	while (string[i] != '\0')
		temp[k++] = string[i++];	
	temp[k] = '\0';
	free (string);
	return (temp);
}

char	*gnl_readingshandler(char *buffer)
{
	char	*string;
	int		i;

	if (buffer == NULL)
		return (NULL);
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

char	*use_read(int fd, char *buffer)
{
	char	*readings;
	char	*temp;
	char	*temp2;
	int		readresult;

	readings = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readings[BUFFER_SIZE] = '\0';
	readresult = read(fd, readings, BUFFER_SIZE);
	readings[readresult] = '\0';
	if ((readresult == 0 && buffer[0] == '\0') || readings == NULL)
	{
		free (readings);
		return (NULL);
	}
	temp = ft_strdup(buffer);
	while (ft_strchr(readings, '\n') == NULL && readresult != 0)
	{
		temp2 = ft_strjoin(temp, readings);
		free(temp);
		free(readings);//
		readresult = read(fd, readings, BUFFER_SIZE);
		readings[readresult] = '\0';
		temp = ft_strdup(temp2);
		free(temp2);
	}
	temp2 = ft_strjoin(temp,readings);
	free(temp);
	free(readings);
	return (temp2);
}



char	*get_next_line(int fd)
{
	static char	*store;
	char		*result;
	char		*helper;
	char		*temp;
	size_t		i;

	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!store)
		store = "";
	helper = use_read(fd, store);
	result = gnl_readingshandler(helper);
	temp = gnl_bufferhandler(helper);
	if (ft_strlen(store) > 0)
		free (store);
	//ft_bzero(store, ft_strlen(store));
	i = ft_strlen(temp);
	store = malloc (sizeof(char *) * (ft_strlen(temp) + 1));
	ft_memcpy(store, temp, i + 1);
	//store[ft_strlen(store)] = '\0';
	free(temp);
	return (result);
}
