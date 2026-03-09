/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppenuela <ppenuela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:40:09 by ppenuela          #+#    #+#             */
/*   Updated: 2024/04/26 21:07:17 by ppenuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_startcount(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (i < ft_strlen(s1))
	{
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				++count;
			++j;
		}
		if (count == 0)
			return (i);
		++i;
		count = 0;
		j = 0;
	}
	return (0);
}

size_t	ft_endcount(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	count = 0;
	while (i > 0 && ft_strlen(s1) > 0)
	{
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				++count;
			++j;
		}
		if (count == 0)
			return (i);
		--i;
		count = 0;
		j = 0;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	start;
	size_t	end;
	size_t	i;

	start = ft_startcount(s1, set);
	end = ft_endcount(s1, set);
	if (end < start || (start == 0 && end == 0))
	{
		copy = (char *)malloc(sizeof(char const));
		if (!copy)
			return (0);
		copy[0] = 0;
		return ((char *)copy);
	}
	copy = (char *)malloc((sizeof(char const)) * (end - start + 2));
	if (!copy)
		return (0);
	i = -1;
	while (++i <= end - start)
		copy[i] = s1[i + start];
	copy[i] = 0;
	return ((char *)copy);
}
/*char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = ft_startcount(s1, set);
	end = ft_endcount(s1, set);
	if (end < start || (start == 0 && end == 0))
	{
		copy = (char *)malloc((sizeof(char const)) * (1));
		copy[i] = 0;
		return ((char *)copy);
	}
	copy = (char *)malloc((sizeof(char const)) * (end - start + 2));
	while (i <= end - start)
	{
		copy[i] = s1[i + start];
		++i;
	}
	copy[i] = 0;
	return ((char *)copy);
}*/