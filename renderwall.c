/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_reda <m_reda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:59:34 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 01:04:31 by m_reda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r * (256 * 256)) + (g * (256)) + (b));
}

void	draw_cieling(int i, int top)
{
	int	color;
	int	y;

	y = 0;
	color = rgb_to_int(g_info.c.red, g_info.c.green, g_info.c.blue);
	while (y < top)
	{
		put_pixel(i, y, color);
		y++;
	}
}

void	draw_flooring(int i, int bottom)
{
	int	color;
	int	y;

	color = rgb_to_int(g_info.f.red, g_info.f.green,
			g_info.f.blue);
	y = bottom;
	while (y < g_info.yR)
	{
		put_pixel(i, y, color);
		y++;
	}
}

void	draw_wall(int i, int top_pixel, int wall_height)
{
	int		dis_from_top;
	int		of_x;
	int		of_y;
	int		y;

	y = top_pixel;
	if (g_info.g_rays[i].was_hit_vert)
		of_x = (int)g_info.g_rays[i].wall_hit_y % TILE_SIZE;
	else
		of_x = (int)g_info.g_rays[i].wall_hit_x % TILE_SIZE;
	while (y < (top_pixel + wall_height))
	{
		dis_from_top = y + (wall_height / 2) - (g_info.yR / 2);
		of_y = dis_from_top * ((float)TEX_HEIGHT / wall_height);
		if (g_info.g_rays[i].up && !g_info.g_rays[i].was_hit_vert)
			put_pixel(i, y, g_info.g_so.buf[(g_info.g_so.width * of_y) + of_x]);
		else if (g_info.g_rays[i].down && !g_info.g_rays[i].was_hit_vert)
			put_pixel(i, y, g_info.g_no.buf[(g_info.g_no.width * of_y) + of_x]);
		else if (g_info.g_rays[i].right && g_info.g_rays[i].was_hit_vert)
			put_pixel(i, y, g_info.g_we.buf[(g_info.g_we.width * of_y) + of_x]);
		else if (g_info.g_rays[i].left && g_info.g_rays[i].was_hit_vert)
			put_pixel(i, y, g_info.g_ea.buf[(g_info.g_ea.width * of_y) + of_x]);
		y++;
	}
}

void	render3d(int i, float ray, float correctwdis, float disproplane)
{
	float	wallheight;
	float	wall_top_pixel;
	float	wall_bottom_pixel;

	i = 0;
	while (i < g_info.xR)
	{
		ray = g_info.g_rays[i].distance;
		correctwdis = ray * cos(normalize_angle(g_info.g_rays[i].ray_angle
					- g_info.player.ra));
		disproplane = (g_info.xR / 2) / tan((60 * (PI / 180)) / 2);
		wallheight = (TILE_SIZE / correctwdis) * disproplane;
		wall_top_pixel = (g_info.yR / 2) - (wallheight / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_bottom_pixel = (g_info.yR / 2) + (wallheight / 2);
		if (wall_bottom_pixel > g_info.yR)
			wall_bottom_pixel = g_info.yR;
		draw_cieling(i, wall_top_pixel);
		draw_wall(i, wall_top_pixel, wallheight);
		draw_flooring(i, wall_bottom_pixel);
		i++;
	}
}
