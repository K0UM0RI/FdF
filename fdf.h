/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbat <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:50:30 by sbat              #+#    #+#             */
/*   Updated: 2025/02/24 03:30:31 by sbat             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# define DIM 1280
# define ON_DESTROY 17
# define ESC 65307
# define ON_KEYDOWN 2   // int (*f)(int keycode, void *param)
# define ON_KEYUP 3     // int (*f)(int keycode, void *param)
# define ON_MOUSEDOWN 4 // int (*f)(int button, int x, int y, void *param)
# define ON_MOUSEUP 5   // int (*f)(int button, int x, int y, void *param)
# define ON_MOUSEMOVE 6 // int (*f)(int x, int y, void *param)
# define ON_EXPOSE 12   // int (*f)(void *param)
# define ON_DESTROY 17  // int (*f)(void *param)
# define ON_MOUSEMOVE 6 // int (*f)(int x, int y, void *param)
# define ARROW_U 65362
# define ARROW_D 65364
# define ARROW_R 65363
# define ARROW_L 65361
# define R_KEY 114
# define MM 2
# define MU 4
# define MD 5
# define ML 1
# define MR 3
# define P_KEY 112
# define C_KEY 99
# define PLUS_KEY 65451
# define MINUS_KEY 65453

typedef struct s_data
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_angle
{
	float		x;
	float		y;
	float		z;
}				t_angle;
typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct s_pointi
{
	int			x;
	int			y;
	int			z;
}				t_pointi;

typedef struct s_p
{
	t_point		p1;
	t_point		p2;
	t_pointi	p3;
	t_pointi	p4;
	int			color1[3];
	int			color2[3];
	int			r;
	int			g;
	int			b;
}				t_p;

typedef struct s_mlxshit
{
	void		*ptr;
	void		*win;
}				t_mlxshit;

typedef struct s_mapdata
{
	int			**map;
	int			lines;
	int			ppline;
	int			**color;
	float		scale;
	int			iscale;
}				t_mapdata;

typedef struct s_keys
{
	int			mousel;
	int			mouser;
	int			prev_x;
	int			prev_y;
	int			arrowu;
	int			arrowd;
	int			arrowr;
	int			arrowl;
	int			plusign;
	int			minusign;
}				t_keys;

typedef struct s_vars
{
	t_mapdata	map;
	t_mlxshit	mlx;
	t_data		img;
	t_keys		key;
	t_angle		angle;
	t_p			p;
	int			x;
	int			y;
	int			dx;
	int			dy;
	float		heightmod;
	int			iso;
}				t_vars;

typedef struct s_drawthread {
    t_vars vars;
    int movex;
    int movey;
} t_drawthread;

typedef struct s_drawxyth
{
    t_vars vars;
    int i;
    int movex;
    int movey;
} t_drawxyth;

// utils
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *c);
char			**ft_split(char const *s, char c);
void			*ft_memset(void *s, int c, size_t n);
int				ft_atoi(const char *nptr);

// utilsutils
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				doublecharlen(char **c);

// errors
int				invalidmap(char *c, t_mapdata *map);
void			ft_putstr_fd(char *s, int fd);
// fetchmap
void			fetchmap(t_mapdata *mapdata, char *av);

// gradiant
void			getrgb(int *po, t_p *p, t_pointi p1, t_pointi p2);
float			gett(int x, int y, t_pointi a, t_pointi b);
float			frac(int x1, int x2, int x);
void			putgradedpixel(t_vars *vars, t_pointi p1, t_pointi p2, int *po);

// frees
void			freed(char **c);
void			freed_n(void **map, int n);
int				cleanandleave(t_vars *vars);

int				ft_ahextoi(const char *str);

void			rotate_z(t_point *point, float angle);
void			rotate_x(t_point *point, float angle);
void			rotate_y(t_point *point, float angle);
void			isometric(t_point *p);

void			drawshape(t_vars vars, int f, char c);
void			redraw(t_vars *vars, int f, char c);
void			drawylines(t_vars vars, int movex, int movey);
void			drawxlines(t_vars vars, int movex, int movey);
void			draw_line(t_vars *vars, t_pointi p1, t_pointi p2);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	convertndraw(t_vars vars, int movex, int movey);
void	convert(t_point *p, int x, int y, t_vars vars);

t_vars			initvars(char *av);
int				toggles(t_vars *vars);
int				keydown(int key, t_vars *vars);
int				keyup(int key, t_vars *vars);

int				mousekeyup(int key, int x, int y, t_vars *vars);
int				mouse_move(int x, int y, t_vars *vars);
int				mousekeydown(int key, int x, int y, t_vars *vars);

//threads
void *drawylines_subth(void* arg);
void *drawxlines_subth(void* arg);
void *drawxlines_mainth(void *arg);
void *drawylines_mainth(void *arg);
#endif
