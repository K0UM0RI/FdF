/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:15:29 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:15:31 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	freed(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

void	freed_n(void **map, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	cleanandleave(t_vars *vars)
{
	mlx_destroy_image(vars->mlx.ptr, vars->img.ptr);
	mlx_destroy_window(vars->mlx.ptr, vars->mlx.win);
	mlx_destroy_display(vars->mlx.ptr);
	free(vars->mlx.ptr);
	freed((char **)vars->map.map);
	freed((char **)vars->map.color);
	exit(0);
}
