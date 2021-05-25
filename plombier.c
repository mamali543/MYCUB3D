#include "include/cub3D.h"

void	free_texture(void)
{
	if (g_info.mlx.mlx)
	{
		if (g_info.g_no.ptr)
			mlx_destroy_image(g_info.mlx.mlx, g_info.g_no.ptr);
		if (g_info.g_so.ptr)
			mlx_destroy_image(g_info.mlx.mlx, g_info.g_so.ptr);
		if (g_info.g_we.ptr)
			mlx_destroy_image(g_info.mlx.mlx, g_info.g_we.ptr);
		if (g_info.g_ea.ptr)
			mlx_destroy_image(g_info.mlx.mlx, g_info.g_ea.ptr);
		if (g_info.g_s.ptr)
			mlx_destroy_image(g_info.mlx.mlx, g_info.g_s.ptr);
	}
}

void	clean_up(void)
{
	free(g_info.no);
	free(g_info.so);
	free(g_info.we);
	free(g_info.ea);
	free(g_info.s);
	free_texture();
	free_str_array(g_info.map);
}
