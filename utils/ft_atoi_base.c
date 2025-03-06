/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:15:16 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:15:18 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

int	ft_ahextoi(const char *c)
{
	int		res;
	int		i;
	char	s;

	res = 0;
	i = 0;
	while (c[i] != '\0')
	{
		s = ft_tolower(c[i]);
		if (s >= '0' && s <= '9')
			res = res * 16 + (s - '0');
		else if (s >= 'a' && s <= 'f')
			res = res * 16 + (s - 'a' + 10);
		else
			break ;
		i++;
	}
	return (res);
}
