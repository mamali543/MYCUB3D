/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:35:49 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 16:27:49 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	cast_rays(void)
{
	float	ray_angle;
	int		strip_id;
	float	fov_angle;

	strip_id = 0;
	fov_angle = (60 * M_PI / 180);
	ray_angle = g_info.player.ra - (30 * M_PI / 180);
	ray_angle = normalize_angle(ray_angle);
	while (strip_id < g_info.xR)
	{
		g_info.ray.down = ray_angle > 0 && ray_angle < M_PI;
		g_info.ray.up = !g_info.ray.down;
		g_info.ray.right = ray_angle < (M_PI / 2) || ray_angle > (1.5 * M_PI);
		g_info.ray.left = !g_info.ray.right;
		cast_horz(ray_angle);
		cast_vert(ray_angle);
		store_rays(strip_id, ray_angle);
		ray_angle = normalize_angle(ray_angle);
		ray_angle += fov_angle / g_info.xR;
		strip_id++;
	}
}

void	update(void)
{
	float	newplayery;
	float	newplayerx;

	g_info.player.ra += g_info.player.tdirec * TURN_SPEED;
	newplayery = g_info.player.y + sin(g_info.player.ra)
		* 60 * g_info.player.wd;
	newplayerx = g_info.player.x + cos(g_info.player.ra)
		* 60 * g_info.player.wd;
	if (!(has_wall_at(newplayerx, newplayery)) && !(has_wall_at_s(\
		newplayerx, newplayery)))
	{
		g_info.player.x += cos(g_info.player.ra)
			* WALK_SPEED * g_info.player.wd;
		g_info.player.y += sin(g_info.player.ra)
			* WALK_SPEED * g_info.player.wd;
	}
}

int	loop_key(void)
{
	g_info.g_img.img = mlx_new_image(g_info.mlx.mlx, g_info.xR, g_info.yR);
	g_info.g_img.addr = (int *)mlx_get_data_addr(g_info.g_img.img,
			&g_info.g_img.bits_per_pixel,
			&g_info.g_img.line_length, &g_info.g_img.endian);
	update();
	cast_rays();
	render3d(0, 0, 0, 0);
	ft_draw_sprites();
	mlx_put_image_to_window(g_info.mlx.mlx, g_info.mlx.mlx_win,
		g_info.g_img.img, 0, 0);
	mlx_destroy_image(g_info.mlx.mlx, g_info.g_img.img);
	return (0);
}

int	main(int argc, char **argv)
{
	ft_initf();
	ft_checkargs(argc, argv);
	ft_readfile(argv, 1);
	ft_inits();
	loop_key();
	if (ft_checksa(argv[2]) == 1 && argc == 3)
		bmp();
	mlx_hook(g_info.mlx.mlx_win, 2, 1L << 0, keypressed, 0);
	mlx_hook(g_info.mlx.mlx_win, 3, 1L << 1, keyreleased, 0);
	mlx_hook(g_info.mlx.mlx_win, 17, 0, quit, NULL);
	mlx_loop_hook(g_info.mlx.mlx, loop_key, 0);
	mlx_loop(g_info.mlx.mlx);
}
