/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:50:14 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:08:31 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_vars *vars, t_pointi p1, t_pointi p2)
{
	int	po[2];

	int (dx), (dy), (err), (err2);
	po[0] = p1.x;
	po[1] = p1.y;
	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	err = dx - dy;
	while (1)
	{
		putgradedpixel(vars, p1, p2, po);
		if (po[0] == p2.x && po[1] == p2.y)
			return ;
		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			po[0] += 1 - 2 * (po[0] > p2.x);
		}
		if (err2 < dx)
		{
			err += dx;
			po[1] += 1 - 2 * (po[1] > p2.y);
		}
	}
}

void	drawshape(t_vars vars, int f, char c)
{
	static int	movex;
	static int	movey;

	if (vars.map.scale > 50)
		f *= vars.map.scale / 7;
	else
		f *= vars.map.scale;
	if (c == 'x')
		movex += f;
	else if (c == 'y')
		movey += f;
	else if (c == 'r')
	{
		movex = 0;
		movey = 0;
	}
	drawxlines(vars, movex, movey);
	drawylines(vars, movex, movey);
	mlx_put_image_to_window(vars.mlx.ptr, vars.mlx.win, vars.img.ptr, 0, 0);
}

void	redraw(t_vars *vars, int f, char c)
{
	mlx_destroy_image(vars->mlx.ptr, vars->img.ptr);
	vars->img.ptr = mlx_new_image(vars->mlx.ptr, DIM, DIM);
	vars->img.addr = mlx_get_data_addr(vars->img.ptr, &vars->img.bits_per_pixel,
			&vars->img.line_len, &vars->img.endian);
	drawshape(*vars, f, c);
}
