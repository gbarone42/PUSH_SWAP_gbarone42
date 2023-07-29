/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barone <barone@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:21:04 by mcerchi           #+#    #+#             */
/*   Updated: 2023/06/15 15:53:01 by barone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	wordcount(const char *str, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*stralloc(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof (char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	int		l;
	size_t	j;
	char	**split;

	split = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	i = 0;
	l = -1;
	j = 0;
	if (!split || !s)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && l < 0)
			l = i;
		else if ((s[i] == c || s[i] == '\0') && l >= 0)
		{
			split[j++] = stralloc(s, l, i);
			l = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*
int	nb_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (j == 0))
		{
			j = 1;
			i++;
		}
		if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	**wds_assign(const char *s, char c, char **dest, size_t len)
{
	size_t	i;
	size_t	x;
	int		j;

	i = 0;
	x = 0;
	j = -1;
	while (i <= len)
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == len) && j >= 0)
		{
			dest[x++] = ft_substr(s, j, (i - j));
			j = -1;
		}
		i++;
	}
	dest[x] = 0;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;

	i = 0;
	if (s[0] == '\0')
		exit(0);
	while (s[i] <= 32 && s[i] != '\0')
	{
		i++;
		if (s[i] == '\0')
			exit(0);
	}
	len = (ft_strlen(s));
	dest = (char **) malloc ((nb_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	wds_assign(s, c, dest, len);
	return (dest);
}
*/