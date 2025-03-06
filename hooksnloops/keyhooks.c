/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:14:32 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:14:34 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	keyup(int key, t_vars *vars)
{
	if (key == ARROW_U)
		vars->key.arrowu = 0;
	else if (key == ARROW_D)
		vars->key.arrowd = 0;
	else if (key == ARROW_R)
		vars->key.arrowr = 0;
	else if (key == ARROW_L)
		vars->key.arrowl = 0;
	else if (key == PLUS_KEY)
		vars->key.plusign = 0;
	else if (key == MINUS_KEY)
		vars->key.minusign = 0;
	return (0);
}

void	resetshape(t_vars *vars, int i)
{
	vars->map.scale = vars->map.iscale;
	vars->angle.x = 0;
	vars->angle.y = 0;
	vars->angle.z = 0;
	vars->dx = 0;
	vars->dy = 0;
	vars->iso = i;
	vars->heightmod = 1;
	redraw(vars, 0, 'r');
}

void	resetiso(t_vars *vars)
{
	vars->angle.x = 0;
	vars->angle.y = 0;
	vars->angle.z = 0;
	vars->iso = 1;
	redraw(vars, 0, 'r');
}

int	keydown(int key, t_vars *vars)
{
	if (key == ARROW_U)
		vars->key.arrowu = 1;
	else if (key == ARROW_D)
		vars->key.arrowd = 1;
	else if (key == ARROW_R)
		vars->key.arrowr = 1;
	else if (key == ARROW_L)
		vars->key.arrowl = 1;
	else if (key == ESC)
		cleanandleave(vars);
	else if (key == PLUS_KEY)
		vars->key.plusign = 1;
	else if (key == MINUS_KEY)
		vars->key.minusign = 1;
	else if (key == R_KEY)
		resetshape(vars, 1);
	else if (key == P_KEY)
		resetshape(vars, 0);
	else if (key == 'i')
		resetiso(vars);
	return (0);
}

int	toggles(t_vars *vars)
{
	if (vars->key.arrowu == 1)
		redraw(vars, 1, 'y');
	if (vars->key.arrowd == 1)
		redraw(vars, -1, 'y');
	if (vars->key.arrowr == 1)
		redraw(vars, -1, 'x');
	if (vars->key.arrowl == 1)
		redraw(vars, 1, 'x');
	if (vars->key.plusign)
	{
		if (vars->heightmod <= 10)
		{
			vars->heightmod += 0.01;
			redraw(vars, 0, 0);
		}
	}
	if (vars->key.minusign)
	{
		if (vars->heightmod >= 0)
		{
			vars->heightmod -= 0.01;
			redraw(vars, 0, 0);
		}
	}
	return (0);
}
