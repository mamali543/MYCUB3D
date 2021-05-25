/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:27:59 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 14:02:53 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	mlx_struct_init(void)
{
	g_info.mlx.mlx = mlx_init();
	init_texture();
	init_texture2();
	g_info.mlx.mlx_win = mlx_new_window(g_info.mlx.mlx, g_info.xR,
			g_info.yR, "cub3D");
}

void	ft_initf(void)
{
	g_info.ret = 0;
	g_info.var = 0;
	g_info.so = NULL;
	g_info.no = NULL;
	g_info.we = NULL;
	g_info.ea = NULL;
	g_info.s = NULL;
	g_info.xR = 0;
	g_info.yR = 0;
	g_info.c.blue = 0;
	g_info.f.blue = 0;
	g_info.c.green = 0;
	g_info.f.green = 0;
	g_info.c.red = 0;
	g_info.f.red = 0;
	g_info.maplwidth = 0;
	g_info.mapheight = 0;
	g_info.map = NULL;
}

static	void	ft_screadfile(int i, int j, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_puterror("invalid file", NULL);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] == '1')
		{
			g_info.map = ft_realloc(g_info.map, line, 0, 0);
			g_info.var = 0;
		}
		else
			free(line);
		j = 0;
	}
}

void	ft_readfile(char **argv, int i)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_puterror("invalid file", NULL);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		ft_checkline(line);
		if (i == 0 && g_info.ret != 8)
			ft_puterror("Check Your File!", NULL);
		free(line);
	}
	ft_screadfile(1, 0, argv);
	if (g_info.map == NULL)
		ft_puterror("INVALID MAP", NULL);
	ft_checkmap(g_info.map, 0, 0);
}
