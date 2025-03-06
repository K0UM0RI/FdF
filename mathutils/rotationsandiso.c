/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotationsandiso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:16:31 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 02:16:33 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_z(t_point *a, float angle)
{
	float	x1;

	x1 = a->x;
	a->x = x1 * cos(angle) - a->y * sin(angle);
	a->y = x1 * sin(angle) + a->y * cos(angle);
}

void	rotate_y(t_point *a, float angle)
{
	float	x1;

	x1 = a->x;
	a->x = x1 * cos(angle) + a->z * sin(angle);
	a->z = a->z * cos(angle) - x1 * sin(angle);
}

void	rotate_x(t_point *a, float angle)
{
	float	y1;

	y1 = a->y;
	a->y = y1 * cos(angle) - a->z * sin(angle);
	a->z = y1 * sin(angle) + a->z * cos(angle);
}

void	isometric(t_point *p)
{
	float	x1;

	x1 = p->x;
	p->x = (x1 - p->y) * cos(0.523599);
	p->y = (x1 + p->y) * sin(0.523599) - p->z;
}
