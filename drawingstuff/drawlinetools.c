/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlinetools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:13:33 by sbat              #+#    #+#             */
/*   Updated: 2025/03/05 00:23:15 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	convert(t_point *p, int x, int y, t_vars vars)
{
	p->x = x - vars.map.ppline / 2 + 0.5 * (vars.map.ppline % 2 == 0);
	p->y = y - vars.map.lines / 2 + 0.5 * (vars.map.lines % 2 == 0);
	if (vars.map.map[y])
		p->z = (vars.map.map[y][x] / 3 * vars.heightmod);
	else
		p->z = 0;
	rotate_z(p, vars.angle.z);
	rotate_x(p, vars.angle.x);
	rotate_y(p, vars.angle.y);
	if (vars.iso)
		isometric(p);
	p->x = (p->x * vars.map.scale / 2) + DIM / 2;
	p->y = (p->y * vars.map.scale / 2) + DIM / 3;
}

void	convertndraw(t_vars vars, int movex, int movey)
{
	vars.p.p3.x = (int)(vars.p.p1.x + movex);
	vars.p.p3.y = (int)(vars.p.p1.y + movey);
	vars.p.p4.x = (int)(vars.p.p2.x + movex);
	vars.p.p4.y = (int)(vars.p.p2.y + movey);
	draw_line(&vars, vars.p.p3, vars.p.p4);
}

void	drawxlines(t_vars vars, int movex, int movey)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars.map.lines)
	{
		x = 0;
		while (x < vars.map.ppline - 1)
		{
			convert(&vars.p.p1, x, y, vars);
			convert(&vars.p.p2, x + 1, y, vars);
			vars.p.color1[0] = (vars.map.color[y][x] >> 16) & 0xFF;
			vars.p.color1[1] = (vars.map.color[y][x] >> 8) & 0xFF;
			vars.p.color1[2] = vars.map.color[y][x] & 0xFF;
			vars.p.color2[0] = (vars.map.color[y][x + 1] >> 16) & 0xFF;
			vars.p.color2[1] = (vars.map.color[y][x + 1] >> 8) & 0xFF;
			vars.p.color2[2] = vars.map.color[y][x + 1] & 0xFF;
			x++;
			convertndraw(vars, movex, movey);
		}
		y++;
	}
}

void	drawylines(t_vars vars, int movex, int movey)
{
	int	y;
	int	x;

	x = 0;
	while (x < vars.map.ppline)
	{
		y = 0;
		while (y < vars.map.lines - 1)
		{
			convert(&vars.p.p1, x, y, vars);
			convert(&vars.p.p2, x, y + 1, vars);
			vars.p.color1[0] = (vars.map.color[y][x] >> 16) & 0xFF;
			vars.p.color1[1] = (vars.map.color[y][x] >> 8) & 0xFF;
			vars.p.color1[2] = vars.map.color[y][x] & 0xFF;
			vars.p.color2[0] = (vars.map.color[y + 1][x] >> 16) & 0xFF;
			vars.p.color2[1] = (vars.map.color[y + 1][x] >> 8) & 0xFF;
			vars.p.color2[2] = vars.map.color[y + 1][x] & 0xFF;
			y++;
			convertndraw(vars, movex, movey);
		}
		x++;
	}
}
