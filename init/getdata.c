/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:14:15 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:14:16 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	max(int x, int y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

float	getscale(t_mapdata map)
{
	int	x;
	int	y;
	int	peak;

	x = 0;
	y = 0;
	peak = 0;
	while (map.map[y])
	{
		x = 0;
		while (x < map.ppline)
		{
			if (abs(map.map[y][x]) > peak)
				peak = abs(map.map[y][x]);
			x++;
		}
		y++;
	}
	return ((DIM - (DIM / 10)) / max(max(map.ppline, map.lines), peak));
}

char	*fetchname(char *av)
{
	char	*c;
	int		i;

	i = ft_strlen(av);
	while (av[i] != '/' && i >= 0)
	{
		if (av[i] == '.')
			av[i] = '\0';
		i--;
	}
	i++;
	av = av + i;
	c = malloc(ft_strlen(av) + 1);
	i = 0;
	while (av[i])
	{
		c[i] = av[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

t_vars	initvars(char *av)
{
	t_vars	vars;
	char	*c;

	ft_memset(&vars, 0, sizeof(t_vars));
	fetchmap(&vars.map, av);
	c = fetchname(av);
	vars.angle.x = 0;
	vars.angle.z = 0;
	vars.angle.y = 0;
	vars.heightmod = 1;
	vars.iso = 1;
	vars.map.scale = getscale(vars.map);
	vars.map.iscale = vars.map.scale;
	vars.mlx.ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.ptr, DIM, DIM, c);
	free(c);
	vars.img.ptr = mlx_new_image(vars.mlx.ptr, DIM, DIM);
	vars.img.addr = mlx_get_data_addr(vars.img.ptr, &vars.img.bits_per_pixel,
			&vars.img.line_len, &vars.img.endian);
	return (vars);
}
