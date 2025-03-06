/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:15:04 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:15:05 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mousekeyup(int key, int x, int y, t_vars *vars)
{
	x++;
	y++;
	if (key == ML)
		vars->key.mousel = 0;
	else if (key == MR)
		vars->key.mouser = 0;
	return (0);
}

int	mousekeydown(int key, int x, int y, t_vars *vars)
{
	x++;
	y++;
	if (key == 5 && vars->map.scale == 0)
		return (0);
	if (key == MU && vars->map.scale <= 100)
		vars->map.scale *= 1.1;
	else if (key == MD)
		vars->map.scale *= 0.9;
	else if (key == MM)
		vars->map.scale = vars->map.iscale;
	redraw(vars, 0, 0);
	if (key == ML)
		vars->key.mousel = 1;
	else if (key == MR)
		vars->key.mouser = 1;
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->key.mousel)
	{
		if (x - vars->key.prev_x > 0)
			vars->dx += 1;
		else if (x - vars->key.prev_x < 0)
			vars->dx -= 1;
		vars->angle.y += vars->dx * 0.0001f;
	}
	if (vars->key.mouser)
	{
		if (y - vars->key.prev_y > 0)
			vars->dy += 1;
		else if (y - vars->key.prev_y < 0)
			vars->dy -= 1;
		vars->angle.z += vars->dy * 0.0001f;
	}
	redraw(vars, 0, 0);
	vars->key.prev_x = vars->x;
	vars->key.prev_y = vars->y;
	return (0);
}
