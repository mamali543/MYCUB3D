/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:25:29 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 11:27:21 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	ft_puterror(char *error, char	**str)
{
	char	*e;

	e = "\033[1;31m Error\n >> \033[0;31m";
	free_str_array(str);
	clean_up();
	ft_putstr_fd(e, 1);
	ft_putstr_fd(error, 1);
	exit(-1);
}

void	schline(int i, char *line, int j)
{
	char	*d;

	while (line[i])
	{
		if (ft_strchr("012 WESN", line[i]))
			i++;
		else
			ft_puterror("Check Your Map!!", NULL);
	}
	d = ft_strtrim(line, " ");
	j = ft_strlen(d) - 1;
	if (d[j] == '1')
	{
		if (i > g_info.maplwidth)
			g_info.maplwidth = i;
		g_info.mapheight++;
		free(d);
	}
	else
	{
		free(d);
		ft_puterror("Check Your Map!!!", NULL);
	}
}

int	keyreleased(int key)
{
	if (key == KEY_8 || key == KEY_UP)
		g_info.player.wd = 0;
	if (key == KEY_2 || key == KEY_DOWN)
		g_info.player.wd = 0;
	if (key == KEY_4 || key == KEY_LEFT)
		g_info.player.tdirec = 0;
	if (key == KEY_6 || key == KEY_RIGHT)
		g_info.player.tdirec = 0;
	return (0);
}

int	keypressed(int key)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(g_info.mlx.mlx, g_info.mlx.mlx_win);
		clean_up();
		exit(0);
	}
	if (key == KEY_8 || key == KEY_UP)
		g_info.player.wd = 1;
	if (key == KEY_2 || key == KEY_DOWN)
		g_info.player.wd = -1;
	if (key == KEY_4 || key == KEY_LEFT)
		g_info.player.tdirec = -1;
	if (key == KEY_6 || key == KEY_RIGHT)
		g_info.player.tdirec = 1;
	return (0);
}

int	quit(void)
{
	exit(-1);
}
