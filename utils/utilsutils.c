/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:14:21 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 03:10:54 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dl;
	size_t	sl;

	if (!src)
		return (size);
	sl = ft_strlen(src);
	if (!dst)
		return (sl);
	dl = ft_strlen(dst);
	j = 0;
	i = dl;
	if (i >= size)
		return (sl + size);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dl + sl);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	if (!src)
		return (0);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || !dst)
		return (slen);
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*v;
	unsigned char	k;

	if (!s)
		return (NULL);
	k = (unsigned char)c;
	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		v[i] = k;
		i++;
	}
	return (s);
}

int	doublecharlen(char **c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	res = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = sign + (-2 * (nptr[i] == '-'));
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}
