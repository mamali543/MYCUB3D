/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:46:06 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 13:45:52 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	init_vert(float ray_angle)
{
	g_info.ray.vert_hit = FALSE;
	g_info.ray.x_inter = floor(g_info.player.x / TILE_SIZE) * TILE_SIZE;
	if (g_info.ray.right)
		g_info.ray.x_inter += TILE_SIZE;
	else
		g_info.ray.x_inter += 0;
	g_info.ray.y_inter = g_info.player.y
		+ (g_info.ray.x_inter - g_info.player.x) * tan(ray_angle);
	g_info.ray.xstep = TILE_SIZE;
	if (g_info.ray.left)
		g_info.ray.xstep *= -1;
	else
		g_info.ray.xstep *= 1;
	g_info.ray.ystep = g_info.ray.xstep * tan(ray_angle);
	if (g_info.ray.up && g_info.ray.ystep > 0)
		g_info.ray.ystep *= -1;
	else
		g_info.ray.ystep *= 1;
	if (g_info.ray.down && g_info.ray.ystep < 0)
		g_info.ray.ystep *= -1;
	else
		g_info.ray.ystep *= 1;
	g_info.ray.next_vert_x = g_info.ray.x_inter;
	g_info.ray.next_vert_y = g_info.ray.y_inter;
}

void	cast_vert(float ray_angle)
{
	init_vert(ray_angle);
	while (g_info.ray.next_vert_x >= 0 && g_info.ray.next_vert_x
		<= g_info.mapcol * TILE_SIZE && g_info.ray.next_vert_y >= 0
		&& g_info.ray.next_vert_y <= g_info.maprow * TILE_SIZE)
	{
		if (g_info.ray.left)
			g_info.ray.check_x = g_info.ray.next_vert_x - 1;
		else
			g_info.ray.check_x = g_info.ray.next_vert_x + 0;
		g_info.ray.check_y = g_info.ray.next_vert_y;
		if (has_wall_at(g_info.ray.check_x, g_info.ray.check_y))
		{
			g_info.ray.vert_hit = TRUE;
			g_info.ray.x_hit_vert = g_info.ray.next_vert_x;
			g_info.ray.y_hit_vert = g_info.ray.next_vert_y;
			break ;
		}
		else
		{
			g_info.ray.next_vert_x += g_info.ray.xstep;
			g_info.ray.next_vert_y += g_info.ray.ystep;
		}
	}
}

void	init_horz(float ray_angle)
{
	g_info.ray.horz_hit = FALSE;
	g_info.ray.y_inter = floor(g_info.player.y / TILE_SIZE) * TILE_SIZE;
	if (g_info.ray.down)
		g_info.ray.y_inter += TILE_SIZE;
	else
		g_info.ray.y_inter += 0;
	g_info.ray.x_inter = g_info.player.x
		+ (g_info.ray.y_inter - g_info.player.y) / tan(ray_angle);
	g_info.ray.ystep = TILE_SIZE;
	if (g_info.ray.up)
		g_info.ray.ystep *= -1;
	else
		g_info.ray.ystep *= 1;
	g_info.ray.xstep = g_info.ray.ystep / tan(ray_angle);
	if (g_info.ray.left && g_info.ray.xstep > 0)
		g_info.ray.xstep *= -1;
	else
		g_info.ray.xstep *= 1;
	if (g_info.ray.right && g_info.ray.xstep < 0)
		g_info.ray.xstep *= -1;
	else
		g_info.ray.xstep *= 1;
	g_info.ray.next_horz_x = g_info.ray.x_inter;
	g_info.ray.next_horz_y = g_info.ray.y_inter;
}

void	cast_horz(float ray_angle)
{
	init_horz(ray_angle);
	while (g_info.ray.next_horz_x >= 0 && g_info.ray.next_horz_x
		<= g_info.mapcol * TILE_SIZE && g_info.ray.next_horz_y >= 0
		&& g_info.ray.next_horz_y <= g_info.maprow * TILE_SIZE)
	{
		g_info.ray.check_x = g_info.ray.next_horz_x;
		if (g_info.ray.up)
			g_info.ray.check_y = g_info.ray.next_horz_y + (-1);
		else
			g_info.ray.check_y = g_info.ray.next_horz_y + 0;
		if (has_wall_at(g_info.ray.check_x, g_info.ray.check_y))
		{
			g_info.ray.horz_hit = TRUE;
			g_info.ray.x_hit_horz = g_info.ray.next_horz_x;
			g_info.ray.y_hit_horz = g_info.ray.next_horz_y;
			break ;
		}
		else
		{
			g_info.ray.next_horz_x += g_info.ray.xstep;
			g_info.ray.next_horz_y += g_info.ray.ystep;
		}
	}
}

void	store_rays(int strip_id, float ray_angle)
{
	if (g_info.ray.horz_hit)
		g_info.ray.horz_distance = distance(g_info.player.x, g_info.player.y,
				g_info.ray.x_hit_horz, g_info.ray.y_hit_horz);
	else
		g_info.ray.horz_distance = (float)INT_MAX;
	if (g_info.ray.vert_hit)
		g_info.ray.vert_distance = distance(g_info.player.x, g_info.player.y,
				g_info.ray.x_hit_vert, g_info.ray.y_hit_vert);
	else
		g_info.ray.vert_distance = (float)INT_MAX;
	if (g_info.ray.horz_distance < g_info.ray.vert_distance)
	{
		g_info.g_rays[strip_id].distance = g_info.ray.horz_distance;
		g_info.g_rays[strip_id].wall_hit_x = g_info.ray.x_hit_horz;
		g_info.g_rays[strip_id].wall_hit_y = g_info.ray.y_hit_horz;
		g_info.g_rays[strip_id].was_hit_vert = FALSE;
	}
	else
	{
		g_info.g_rays[strip_id].distance = g_info.ray.vert_distance;
		g_info.g_rays[strip_id].wall_hit_x = g_info.ray.x_hit_horz;
		g_info.g_rays[strip_id].wall_hit_y = g_info.ray.y_hit_vert;
		g_info.g_rays[strip_id].was_hit_vert = TRUE;
	}
	plombier(strip_id, ray_angle);
}
