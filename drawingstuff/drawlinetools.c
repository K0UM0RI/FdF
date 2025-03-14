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

void drawxlines(t_vars vars, int movex, int movey) {
    int y;
    pthread_t threads[vars.map.lines];
    t_drawxyth thread_args[vars.map.lines];

	y = 0;
    while (y < vars.map.lines)
	{
        thread_args[y].vars = vars;
        thread_args[y].i = y;
        thread_args[y].movex = movex;
        thread_args[y].movey = movey;
        pthread_create(&threads[y], NULL, drawxlines_subth, &thread_args[y]);
		y++;
    }
	y = 0;
	while (y < vars.map.lines)
        pthread_join(threads[y++], NULL);
}

void drawylines(t_vars vars, int movex, int movey) {
    int x;
    pthread_t threads[vars.map.ppline];
    t_drawxyth thread_args[vars.map.ppline];

	x = 0;
    while (x < vars.map.ppline)
	{
        thread_args[x].vars = vars;
        thread_args[x].i = x;
        thread_args[x].movex = movex;
        thread_args[x].movey = movey;
        pthread_create(&threads[x], NULL, drawylines_subth, &thread_args[x]);
		x++;
    }
	x = 0;
    while (x < vars.map.ppline) 
        pthread_join(threads[x++], NULL);
}
