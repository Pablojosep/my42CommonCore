/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:30:20 by ppenuela          #+#    #+#             */
/*   Updated: 2024/05/01 19:30:11 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntwrd(char const *s, char c)
{
	int	i;
	int	find;
	int	count;

	i = -1;
	find = 0;
	count = 0;
	while (++i < (int)ft_strlen(s))
	{
		if (s[i] == c)
		{
			if (i == 0 && s[i] == c)
				find = 1;
			if (find == 0)
			{
				++count;
				find = 1;
			}
		}
		else
			find = 0;
	}
	if (s[i - 1] != c && *s != '\0')
		++count;
	return (count);
}

int	ft_lenwc(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c)
			++count;
		++i;
	}
	return (ft_strlen(s) - count);
}

int	ft_countltrsplit(const char *s, int k, char c)
{
	int	i;
	int	cntwrd;

	i = 0;
	cntwrd = 0;
	while (i < ft_lenwc(s, c) && s[k] != c && s[k] != 0)
	{
		++i;
		++k;
		++cntwrd;
	}
	return (cntwrd);
}

int	ft_copycreate(char **copy, int cntwrd, int j)
{
	copy[j] = (char *)malloc (sizeof(char) * (cntwrd + 1));
	if (!copy[j])
	{
		while (j > 0)
		{
			j--;
			free (copy[j]);
		}
		free (copy);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;
	int		j;
	int		i;
	int		k;
	int		cntwrd;

	copy = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c) + 1));
	if (!copy || !s)
		return (0);
	j = 0;
	k = 0;
	while (j < ft_cntwrd(s, c) && k < (int)ft_strlen(s))
	{
		while (s[k] == c)
			++k;
		cntwrd = ft_countltrsplit(s, k, c);
		if (ft_copycreate(copy, cntwrd, j) == 0)
			return (0);
		i = 0;
		while (i < cntwrd)
			copy[j][i++] = s[k++];
		copy[j++][i] = '\0';
	}
	copy[j] = 0;
	return (copy);
}
