/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:23:43 by sbat              #+#    #+#             */
/*   Updated: 2025/03/05 00:24:41 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_ishexa(int c)
{
	if ((c > 47 && c < 58) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	checklines(char *c, t_mapdata *map)
{
	int		i;
	char	**tmp;
	char	**tmp1;

	i = 0;
	tmp = ft_split(c, '\n');
	while (tmp[i])
	{
		tmp1 = ft_split(tmp[i], ' ');
		if (i == 0)
			map->ppline = doublecharlen(tmp1);
		else
		{
			if (map->ppline != doublecharlen(tmp1))
				return (freed(tmp1), freed(tmp), 1);
		}
		i++;
		freed(tmp1);
	}
	freed(tmp);
	return (0);
}

int	invalidmap(char *c, t_mapdata *map)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	if (!c)
		return (1);
	while (c[i])
	{
		if (r)
			r = !ft_isdigit(c[i]);
		if (!ft_ishexa(c[i]) && c[i] != ' ' && c[i] != '\n' && c[i] != ','
			&& c[i] != 'x' && c[i] != '-')
			return (1);
		i++;
	}
	return (r || checklines(c, map));
}
