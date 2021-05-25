/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:37:35 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 11:30:17 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	init_texture(void)
{
	g_info.g_no.ptr = mlx_xpm_file_to_image(g_info.mlx.mlx, g_info.no,
			&g_info.g_no.width, &g_info.g_no.height);
	if (!g_info.g_no.ptr)
		return (ft_puterror("Error\nTexture file not found!\n", NULL));
	g_info.g_no.buf = (int *)mlx_get_data_addr(g_info.g_no.ptr,
			&g_info.g_no.bpp, &g_info.g_no.size_line,
			&g_info.g_no.endian);
	g_info.g_so.ptr = mlx_xpm_file_to_image(g_info.mlx.mlx, g_info.so,
			&g_info.g_so.width, &g_info.g_so.height);
	if (!g_info.g_so.ptr)
		return (ft_puterror("Error\nTexture file not found!\n", NULL));
	g_info.g_so.buf = (int *)mlx_get_data_addr(g_info.g_so.ptr,
			&g_info.g_so.bpp, &g_info.g_so.size_line,
			&g_info.g_so.endian);
	g_info.g_we.ptr = mlx_xpm_file_to_image(g_info.mlx.mlx, g_info.we,
			&g_info.g_we.width, &g_info.g_we.height);
	if (!g_info.g_we.ptr)
		return (ft_puterror("Error\nTexture file not found!\n", NULL));
	g_info.g_we.buf = (int *)mlx_get_data_addr(g_info.g_we.ptr,
			&g_info.g_we.bpp, &g_info.g_we.size_line,
			&g_info.g_we.endian);
}

void	init_texture2(void)
{
	g_info.g_ea.ptr = mlx_xpm_file_to_image(g_info.mlx.mlx, g_info.ea,
			&g_info.g_ea.width, &g_info.g_ea.height);
	if (!g_info.g_ea.ptr)
		return (ft_puterror("Error\nTexture file not found!\n", NULL));
	g_info.g_ea.buf = (int *)mlx_get_data_addr(g_info.g_ea.ptr,
			&g_info.g_ea.bpp, &g_info.g_ea.size_line,
			&g_info.g_ea.endian);
	g_info.g_s.ptr = mlx_xpm_file_to_image(g_info.mlx.mlx, g_info.s,
			&g_info.g_s.width, &g_info.g_s.height);
	if (!g_info.g_s.ptr)
		return (ft_puterror("Error\nTexture file not found!\n", NULL));
	g_info.g_s.buf = (int *)mlx_get_data_addr(g_info.g_s.ptr,
			&g_info.g_s.bpp, &g_info.g_s.size_line,
			&g_info.g_s.endian);
}

void	ft_initplayer(void)
{
	g_info.maprow = g_info.mapheight;
	g_info.mapcol = g_info.maplwidth;
	g_info.player.tdirec = 0;
	g_info.player.wd = 0;
	g_info.player.nor = TILE_SIZE * g_info.maplwidth;
	g_info.player.fov = 60 * (M_PI / 180);
	if (g_info.p == 'N')
		g_info.player.ra = (270 * M_PI / 180);
	else if (g_info.p == 'S')
		g_info.player.ra = (90 * M_PI / 180);
	else if (g_info.p == 'W')
		g_info.player.ra = (180 * M_PI / 180);
	else if (g_info.p == 'E')
		g_info.player.ra = (360 * M_PI / 180);
}

void	init_rays(void)
{
	g_info.g_rays = malloc(sizeof(t_rays) * (g_info.xR));
	if (!g_info.g_rays)
		return ;
}

void	ft_inits(void)
{
	ft_initplayer();
	init_rays();
	mlx_struct_init();
}
