/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:48:00 by sbat              #+#    #+#             */
/*   Updated: 2025/01/16 09:48:03 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hooksnloops(t_vars *vars)
{
	mlx_hook(vars->mlx.win, ON_KEYDOWN, 1L << 0, keydown, vars);
	mlx_hook(vars->mlx.win, ON_KEYUP, 1L << 1, keyup, vars);
	mlx_hook(vars->mlx.win, ON_MOUSEDOWN, (1L << 2), mousekeydown, vars);
	mlx_hook(vars->mlx.win, ON_MOUSEUP, (1L << 3), mousekeyup, vars);
	mlx_hook(vars->mlx.win, ON_MOUSEMOVE, (1L << 6), mouse_move, vars);
	mlx_loop_hook(vars->mlx.ptr, toggles, vars);
	mlx_hook(vars->mlx.win, ON_DESTROY, 0, cleanandleave, vars);
	mlx_loop(vars->mlx.ptr);
}

int	vername(char *c)
{
	char	*f;
	int		i;

	f = ".fdf";
	if (!c)
		return (0);
	i = ft_strlen(c) - 4;
	while (c[i] && *f)
	{
		if (c[i] != *f++)
			return (0);
		i++;
	}
	if (c[i])
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2 || !vername(av[1]))
		return (ft_putstr_fd("Invalid input\n", 2), 1);
	vars = initvars(av[1]);
	drawshape(vars, 0, 0);
	hooksnloops(&vars);
}
