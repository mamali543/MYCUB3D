/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:03:55 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 10:10:25 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

float	distance1(float x1, float y1, float x2, float y2)
{
	return (hypotf((x2 - x1)
			, (y2 - y1)));
}

void	ft_draw_sprites(void)
{
	int			i;

	i = 0;
	while (i < g_info.nbr_sprite)
	{
		g_info.g_s_data[i].distance = distance1(g_info.player.x, g_info.player.y, \
				g_info.g_s_data[i].coord_x,
				g_info.g_s_data[i].coord_y);
		i++;
	}
	ft_sort_sprites();
	i = 0;
	while (i < g_info.nbr_sprite)
		ft_sprite(i++);
}

void	render_spt(int x, int y, int sp_size, int k)
{
	int			color;
	int			i;
	int			j;

	i = 0;
	color = 0xFF45FF;
	while (i++ < sp_size)
	{
		if (x + i < 0 || x + i > g_info.xR)
			continue ;
		if (g_info.g_s_data[k].distance >= g_info.g_rays[x + i].distance)
			continue ;
		j = 0;
		while (j++ < sp_size)
		{
			if ((int)(g_info.g_s.height * (j * g_info.g_s.width / sp_size) + (i * \
g_info.g_s.height / sp_size)) < g_info.g_s.width * g_info.g_s.height)
				color = g_info.g_s.buf[(int)(g_info.g_s.height * (j * \
g_info.g_s.width / sp_size) + (i * g_info.g_s.height / sp_size))];
			if (color > 0)
				put_pixel(x + i, y + j, color);
		}
	}
}

void	ft_sprite(int i)
{
	float		sp_size;
	float		x_inter;
	float		y_inter;
	float		sp_angle;

	sp_angle = atan2(g_info.g_s_data[i].coord_y - \
			g_info.player.y, g_info.g_s_data[i].coord_x - g_info.player.x);
	while (sp_angle - g_info.player.ra > M_PI)
		sp_angle -= 2 * M_PI;
	while (sp_angle - g_info.player.ra < -M_PI)
		sp_angle += 2 * M_PI;
	if (g_info.yR > g_info.xR)
		sp_size = (g_info.yR / g_info.g_s_data[i].distance) * TILE_SIZE;
	else
		sp_size = (g_info.xR / g_info.g_s_data[i].distance) * TILE_SIZE;
	y_inter = g_info.yR / 2 - sp_size / 2;
	x_inter = (sp_angle - g_info.player.ra) / \
			(60 * (PI / 180)) * g_info.xR + (g_info.xR / 2 - sp_size / 2);
	render_spt(x_inter, y_inter, sp_size, i);
}

void	ft_sort_sprites(void)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < g_info.nbr_sprite)
	{
		j = 0;
		while (j < g_info.nbr_sprite - 1)
		{
			if (g_info.g_s_data[j].distance < g_info.g_s_data[j + 1].distance)
			{
				temp = g_info.g_s_data[j];
				g_info.g_s_data[j] = g_info.g_s_data[j + 1];
				g_info.g_s_data[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
