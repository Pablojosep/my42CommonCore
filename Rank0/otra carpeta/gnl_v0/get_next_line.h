/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:37:29 by ppenuela          #+#    #+#             */
/*   Updated: 2024/07/24 20:58:50 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
//char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	ft_bzero(char *s, size_t n);
char	*gnlcopybge(char *content);
int		gnlfindnl(char *content);
char	*ft_strjoin(char const *s1, char const *s2); //ver abajo
char	*gnljntline(char *s1, char *s2);			// ver arriba
char	*ft_strdup(char *src);
char	*gnlcutbeforeln(char *string);
char	*gnlcutafterln(char *string);

#endif