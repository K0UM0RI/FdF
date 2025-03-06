/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <sbat@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:42:51 by sbat              #+#    #+#             */
/*   Updated: 2024/11/03 12:38:15 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static size_t	countwords(const char *s, char c)
{
	size_t	l;

	l = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			l++;
		while (*s && *s != c)
			s++;
	}
	return (l);
}

static void	wordlen(const char *s, char c, size_t *d, size_t *b)
{
	while (s[*b] == c && s[*b])
		*b = *b + 1;
	*d = *b;
	while (s[*b] != c && s[*b])
		*b = *b + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;
	size_t	j;
	size_t	d;
	size_t	b;

	if (!s)
		return (NULL);
	count = countwords(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (perror("ft_split: malloc error"), free(str), NULL);
	j = 0;
	b = 0;
	while (j < count)
	{
		wordlen(s, c, &d, &b);
		str[j] = (char *)malloc(sizeof(char) * (b - d + 1));
		if (!str[j])
			return (perror("ft_split: malloc error"), freed_n((void **)str, j),
				NULL);
		ft_strlcpy(str[j++], s + d, b - d + 1);
	}
	str[count] = NULL;
	return (str);
}
