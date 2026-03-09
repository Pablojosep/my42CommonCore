/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:38:40 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/24 21:24:14 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnljntline(char *s1, char *s2)	//line = s1 - content = s2
{
	char	*copy;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s2[i] != '\n' && s2[i] != '\0')
		++i;
	copy = malloc(sizeof(char *) * (ft_strlen(s1) + i + 1));
	i = 0;
	while (s1[k] != '\0')
	{
		copy[k] = s1[k];
		k++;
	}
	while (s2[i] != '\0' && s2[i] != '\n')
	{
		copy[k + i] = s2[i];
		i++;
	}
	copy[k + i] = '\0';
	return (copy);
}

int	gnlfindnl(char *content)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (content == NULL)
		return (-1);
	while (content[i] != '\0')
	{
		if (content[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*gnlcopybge(char *content)
{
	char	*temporal;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		++i;
	temporal = malloc(sizeof(char *) * (ft_strlen(content) - i + 1));
	if (content[i] == '\n')
		++i;
	while (content[i] != '\0')
	{
		temporal[j] = content[i];
		i++;
		j++;
	}
	temporal[j] = '\0';
	return (temporal);
}

char	*gnlcutbeforeln(char *string)
{
	int		i;
	char	*cut;

	i = 0;
	while (string[i] != '\n')
		++i;
	cut = malloc(sizeof(char *) * (i + 1)); //puede no necesitar el 1
	i = 0;
	while (string[i] != '\n')
	{
		cut[i] = string[i];
		++i;
	}
	cut[i] = '\0';
	return (cut);
}

char	*gnlcutafterln(char *string)
{
	char	*copy;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (string[i] != '\n')
		++i;
	copy = malloc (sizeof(char *) * (ft_strlen(string) - i + 1));
	if (string[i] == '\n')
		++i;
	while (string[i] != '\0')
	{
		copy[k] = string[i];
		++k;
		++i;
	}
	copy[k] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	size_t		result;
	char		*content;
	static char	*baggage;
	char		*line;
	char		*temp;

	if (fd == -1)
		return (NULL);
	result = 0;
	if (!baggage)
	{
		baggage = malloc(sizeof(char *));
		baggage = NULL;
	}
	if (gnlfindnl(baggage) == 1)
	{
		line = gnlcutbeforeln(baggage);
		baggage = gnlcutafterln(baggage);
		temp = ft_strjoin(line, "\n");
		free (line);
		return(temp);
	}
	content = malloc(sizeof(char *) * (BUFFER_SIZE + 1)); //quit'e el mas uno
	if (!content)
		return (NULL);
	result = read(fd, content, BUFFER_SIZE);
	content[BUFFER_SIZE] = '\0';
	if (result == 0 && ft_strlen(baggage) == 0)
	{
		free (content);
		free (line);
		free (baggage);
		free (temp);
		return (NULL);
	}
	if (baggage != NULL)
		content = gnljntline(baggage, content);
	//else
	//	line = ft_strdup(content);
	if (gnlfindnl(content) == 1)
	{
		line = gnlcutbeforeln(content);
		baggage = gnlcutafterln(content);
		temp = ft_strjoin(line, "\n");
		free (line);
		free (content);
		return(temp);
	}
	//if (!line)
		line = ft_strjoin("",content);
	while (gnlfindnl(line) == 0 && result != 0)  //hay q revisar para el fin del archivo de texto
	{
		if (content)
			free (content);
		content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		result = read(fd, content, BUFFER_SIZE);
		content[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, content);;
	}
	if (result != 0)			// para que mierda es esto?
	{
		baggage = gnlcutafterln(line);
		line = gnlcutbeforeln(line);
	}
	temp = ft_strjoin(line,"\n");
	free (line);
	free (content);
	return (temp);
}
