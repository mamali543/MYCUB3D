#include "include/cub3D.h"

void	put_pixel(int x, int y, int color)
{
	if ((x >= 0 && x < g_info.xR && y >= 0 && y < g_info.yR))
		g_info.g_img.addr[(x + (y * g_info.xR))] = color;
}

void	draw_square(int width, int height, int x, int y)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i <= height)
	{
		k = x;
		j = 0;
		while (j <= width)
		{
			put_pixel(k, y, 0xFFFFFF);
			k++;
			j++;
		}
		y++;
		i++;
	}
}

void	draw_map(void)
{
	int		i;
	int		j;
	float	mx;
	float	my;

	mx = 0;
	my = 0;
	i = 0;
	while (i < g_info.maprow)
	{
		j = 0;
		while (j < g_info.mapcol)
		{
			if (g_info.map[i][j] == '1')
				draw_square(TILE_SIZE, TILE_SIZE, mx, my);
			mx += TILE_SIZE;
			j++;
		}
		mx = 0;
		my += TILE_SIZE;
		i++;
	}
}

int	has_wall_at_s(float x, float y)
{
	int	x0;
	int	y0;

	x0 = floor(x / TILE_SIZE);
	y0 = floor(y / TILE_SIZE);
	if (x0 < 0 || x0 >= g_info.mapcol || y0 < 0 || y0 >= g_info.maprow)
		return (1);
	if (g_info.map[y0][x0] == '2')
		return (1);
	return (0);
}

int	has_wall_at(float x, float y)
{
	int		mapX;
	int		mapY;

	mapX = floor(x / TILE_SIZE);
	mapY = floor(y / TILE_SIZE);
	if (mapX < 0 || mapX >= g_info.mapcol || mapY < 0 || mapY >= g_info.maprow)
		return (1);
	if (g_info.map[mapY][mapX] == '1')
	{
		return (1);
	}
	return (0);
}
