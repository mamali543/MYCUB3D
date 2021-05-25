/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:31:32 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 17:39:32 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

float	distance(float x1, float y1, float x2, float y2)
{
	float		dis;

	dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (dis == 0)
		return (EPSILON);
	return (dis);
}

void	ft_getspath(char *line, char **str, int j)
{
	str = ft_split(line, ' ');
	while (str[j])
		j++;
	if (j == 2)
	{
		g_info.s = ft_strtrim(line + 2, " ");
		free_str_array(str);
		g_info.ret++;
	}
	else
		ft_puterror("Invalid Coordinates Of Sprite Texture!", str);
}

void	ft_getf(char *line, char **str, int i, int k)
{
	k = ft_strlen(line);
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) && ft_isdigit(line[k - 1]))
	{
		str = ft_split(line + i, ',');
		if (ft_lineisdigit(str) != 3 || (ft_atoi(str[0]) < 0
				|| ft_atoi(str[1]) < 0 || ft_atoi(str[2]) < 0
				|| ft_atoi(str[0]) > 256 || ft_atoi(str[1]) > 256
				|| ft_atoi(str[2]) > 256))
			ft_puterror("Invalid Coordinates Of f!", str);
		else
		{
			g_info.f.red = ft_atoi(str[0]);
			g_info.f.green = ft_atoi(str[1]);
			g_info.f.blue = ft_atoi(str[2]);
			g_info.ret++;
		}
		free_str_array(str);
	}
	else
		ft_puterror("Check your floor coordinates!", str);
}

void	ft_getc(char *line, char **str, int i, int k)
{
	k = ft_strlen(line);
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) && ft_isdigit(line[k - 1]))
	{
		str = ft_split(line + i, ',');
		if (ft_lineisdigit(str) != 3 || (ft_atoi(str[0]) < 0
				|| ft_atoi(str[1]) < 0 || ft_atoi(str[2]) < 0
				|| ft_atoi(str[0]) > 256 || ft_atoi(str[1]) > 256
				|| ft_atoi(str[2]) > 256 ))
			ft_puterror("Invalid Coordinates Of c!", str);
		else
		{
			g_info.c.red = ft_atoi(str[0]);
			g_info.c.green = ft_atoi(str[1]);
			g_info.c.blue = ft_atoi(str[2]);
			g_info.ret++;
		}
		free_str_array(str);
	}
	else
		ft_puterror("Check your ceiling coordinates!", str);
}

void	ft_getcolors(char *line)
{
	char	**str;

	str = NULL;
	if (!(strncmp(line, "F ", 2)))
		ft_getf(line + 2, str, 0, 0);
	else if (!(strncmp(line, "C ", 2)))
		ft_getc(line + 2, str, 0, 0);
}
