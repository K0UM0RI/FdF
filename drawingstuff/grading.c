/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:27:08 by sbat              #+#    #+#             */
/*   Updated: 2025/03/06 17:27:11 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	frac(int x1, int x2, int x)
{
	if (x1 != x2)
		return ((float)abs(x - x1) / (float)abs(x2 - x1));
	return (0.0f);
}

float	gett(int x, int y, t_pointi a, t_pointi b)
{
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		return (frac(a.x, b.x, x));
	else
		return (frac(a.y, b.y, y));
}

void	getrgb(int *po, t_p *p, t_pointi p1, t_pointi p2)
{
	float	t;

	t = gett(po[0], po[1], p1, p2);
	p->r = p->color1[0] + (p->color2[0] - p->color1[0]) * t;
	p->g = p->color1[1] + (p->color2[1] - p->color1[1]) * t;
	p->b = p->color1[2] + (p->color2[2] - p->color1[2]) * t;
}

void	putgradedpixel(t_vars *vars, t_pointi p1, t_pointi p2, int *po)
{
	getrgb(po, &vars->p, p1, p2);
	if (po[0] < DIM && po[0] >= 0 && po[1] < DIM && po[1] >= 0)
		my_mlx_pixel_put(&vars->img, po[0], po[1],
			(vars->p.r << 16) | (vars->p.g << 8) | vars->p.b);
}
