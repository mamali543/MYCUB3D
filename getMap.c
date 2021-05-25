/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:27:55 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 17:48:13 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	firstALastLines(char **s, int i, int j)
{
	while (s[i][j])
	{
		if (s[i][j] != '1' && s[i][j] != ' ')
			ft_puterror("Check Your Map|", NULL);
		j++;
	}
	j = 0;
	while (s[g_info.mapheight - 1][j])
	{
		if (s[g_info.mapheight - 1][j] != '1'
			&& s[g_info.mapheight - 1][j] != ' ')
			ft_puterror("Check Your Map!", NULL);
		j++;
	}
}

void	ft_mvalidplayer(char **s, int i, int j)
{
	if (g_info.var == 0)
	{
		g_info.player.x = j * TILE_SIZE + TILE_SIZE / 2;
		g_info.player.y = i * TILE_SIZE + TILE_SIZE / 2;
		g_info.p = s[i][j];
		g_info.var = 1;
	}
	else
		ft_puterror("Check Your map@!", NULL);
}

void	validplayer(char **s, int i, int j, int c)
{
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] == '2')
			{
				g_info.g_s_data[c].coord_x = j * TILE_SIZE + TILE_SIZE / 2;
				g_info.g_s_data[c].coord_y = i * TILE_SIZE + TILE_SIZE / 2;
				g_info.nbr_sprite++;
				c++;
			}
			if (s[i][j] == 'N' || s[i][j] == 'W'
				|| s[i][j] == 'E' || s[i][j] == 'S')
				ft_mvalidplayer(s, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (g_info.var != 1)
		ft_puterror("CHECK YOUR FILE: No g_info.player! OR Invalid Map!", NULL);
}

void	ft_checkmap(char **s, int i, int j)
{
	firstALastLines(s, 0, 0);
	validplayer(s, 0, 0, 0);
	i = 1;
	while (i < g_info.mapheight)
	{
		while (s[i][j])
		{
			if (s[i][j] == 'N' || s[i][j] == 'W'
				|| s[i][j] == 'E' || s[i][j] == 'S'
				|| s[i][j] == '0' || s[i][j] == '2')
			{
				if (s[i][j + 1] == ' ' || s[i][j - 1] == ' '
					|| s[i + 1][j] == ' ' || s[i - 1][j] == ' ')
					ft_puterror("Check Your Map!", NULL);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	tablen(char **s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != NULL)
			i++;
	return (i);
}
