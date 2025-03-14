#include "../fdf.h"

void *drawxlines_subth(void* arg)
{
    t_drawxyth *data;
    int x;

    data = (t_drawxyth*)arg;
	x = 0;
    while (x < data->vars.map.ppline - 1)
	{
        convert(&data->vars.p.p1, x, data->i, data->vars);
        convert(&data->vars.p.p2, x + 1, data->i, data->vars);
        data->vars.p.color1[0] = (data->vars.map.color[data->i][x] >> 16) & 0xFF;
        data->vars.p.color1[1] = (data->vars.map.color[data->i][x] >> 8) & 0xFF;
        data->vars.p.color1[2] = data->vars.map.color[data->i][x] & 0xFF;
        data->vars.p.color2[0] = (data->vars.map.color[data->i][x + 1] >> 16) & 0xFF;
        data->vars.p.color2[1] = (data->vars.map.color[data->i][x + 1] >> 8) & 0xFF;
        data->vars.p.color2[2] = data->vars.map.color[data->i][x + 1] & 0xFF;
        x++;
        convertndraw(data->vars, data->movex, data->movey);
    }
    return (NULL);
}

void *drawylines_subth(void* arg) 
{
    t_drawxyth *data;
    int y;

    data = (t_drawxyth*)arg;
	y = 0;
    while (y < data->vars.map.lines - 1) {
        convert(&data->vars.p.p1, data->i, y, data->vars);
        convert(&data->vars.p.p2, data->i, y + 1, data->vars);
        data->vars.p.color1[0] = (data->vars.map.color[y][data->i] >> 16) & 0xFF;
        data->vars.p.color1[1] = (data->vars.map.color[y][data->i] >> 8) & 0xFF;
        data->vars.p.color1[2] = data->vars.map.color[y][data->i] & 0xFF;
        data->vars.p.color2[0] = (data->vars.map.color[y + 1][data->i] >> 16) & 0xFF;
        data->vars.p.color2[1] = (data->vars.map.color[y + 1][data->i] >> 8) & 0xFF;
        data->vars.p.color2[2] = data->vars.map.color[y + 1][data->i] & 0xFF;
        y++;
        convertndraw(data->vars, data->movex, data->movey);
    }
    return (NULL);
}

void *drawxlines_mainth(void *arg)
{
    t_drawthread *data;

    data = (t_drawthread *)arg;
    drawxlines(data->vars, data->movex, data->movey);
    return (NULL);
}

void *drawylines_mainth(void *arg)
{
    t_drawthread *data;

    data = (t_drawthread *)arg;
    drawylines(data->vars, data->movex, data->movey);
    return (NULL);
}