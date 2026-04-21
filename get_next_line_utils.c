/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmattela <tmattela@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-21 10:40:33 by tmattela          #+#    #+#             */
/*   Updated: 2026-04-21 10:40:33 by tmattela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > (s_len - start))
		len = (s_len - start);
	sub = malloc(sizeof(char) * (len +1));
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	find_char_index(char *s, int c)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	sjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sjoin)
		return (NULL);
	while (s1[i])
	{
		sjoin[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		sjoin[j++] = s2[i];
		i++;
	}
	sjoin[j] = '\0';
	return (sjoin);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}



