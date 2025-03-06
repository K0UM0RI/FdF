/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetchmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:15:52 by sbat              #+#    #+#             */
/*   Updated: 2025/02/26 23:45:55 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	readmap(char **c, int mapfd, t_mapdata *map)
{
	char	*line;
	char	*tmp;

	line = get_next_line(mapfd);
	while (line)
	{
		if (line[0] != '\n')
			map->lines++;
		tmp = *c;
		*c = ft_strjoin(*c, line);
		if (tmp)
			free(tmp);
		if (!*c)
			(free(line), exit(1));
		free(line);
		line = get_next_line(mapfd);
	}
}

void	fillmapncolors(char **elems, t_mapdata *map, int y)
{
	int	x;
	int	i;

	x = 0;
	while (elems[x])
	{
		map->map[y][x] = ft_atoi(elems[x]);
		i = 0;
		while (elems[x][i] != ',' && elems[x][i])
			i++;
		if (!elems[x][i])
			map->color[y][x] = 0xFFFFFF;
		else if (elems[x][i + 1] == '0' && elems[x][i + 2] == 'x')
			map->color[y][x] = ft_ahextoi(elems[x] + i + 3);
		else
			map->color[y][x] = 0xFFFFFF;
		x++;
	}
	freed(elems);
}

int	splitmap(char **tmp, t_mapdata *map, int y)
{
	char	**elems;

	while (tmp[y])
	{
		elems = ft_split(tmp[y], ' ');
		if (!elems)
			(freed(tmp), exit(1));
		map->map[y] = malloc(sizeof(int) * (map->ppline + 1));
		if (!map->map[y])
			(freed_n((void **)map->map, y), freed_n((void **)map->color, y),
				freed(elems), freed(tmp), exit(1));
		map->color[y] = malloc(sizeof(int) * (map->ppline + 1));
		if (!map->color[y])
			(freed_n((void **)map->map, y + 1), freed_n((void **)map->color, y),
				freed(elems), freed(tmp), exit(1));
		fillmapncolors(elems, map, y);
		y++;
	}
	freed(tmp);
	return (y);
}

void	initmap(t_mapdata *map, char *c)
{
	int		y;
	char	**tmp;

	tmp = ft_split(c, '\n');
	if (!tmp)
		(free(c), exit(1));
	y = 0;
	y = splitmap(tmp, map, y);
	if (y == -1)
		(ft_putstr_fd("inconsistent lines\n", 2), exit(1));
	map->color[y] = NULL;
	map->map[y] = NULL;
}

void	fetchmap(t_mapdata *map, char *av)
{
	char	*c;
	int		mapfd;

	c = NULL;
	map->lines = 0;
	map->ppline = 0;
	mapfd = open(av, O_RDONLY, 0777);
	if (mapfd == -1)
		(perror("file error"), exit(1));
	readmap(&c, mapfd, map);
	if (invalidmap(c, map))
		(ft_putstr_fd("Invalid map!\n", 2), free(c), exit(1));
	map->map = malloc(sizeof(int *) * (map->lines + 2));
	if (!map->map)
		(perror("fdf: malloc error"), free(c), exit(1));
	map->color = malloc(sizeof(int *) * (map->lines + 2));
	if (!map->map)
		(perror("fdf: malloc error"), free(map->map), free(c), exit(1));
	initmap(map, c);
	free(c);
}
