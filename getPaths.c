/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:46:37 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 13:56:54 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	ft_getsouthpath(char *line, int j)
{
	int		fd;
	char	**str;

	str = ft_split(line, ' ');
	while (str[j])
		j++;
	if (j == 2)
	{
		g_info.so = ft_strtrim(line + 3, " ");
		free_str_array(str);
		g_info.ret++;
		fd = open(g_info.so, O_RDONLY);
		if (fd == -1)
			ft_puterror("Invalid File HHHH", str);
	}
	else
		ft_puterror("Invalid Coordinates Of South Texture!", str);
}

void	ft_getnorthpath(char *line, int j)
{
	int		fd;
	char	**str;

	str = ft_split(line, ' ');
	while (str[j])
		j++;
	if (j == 2)
	{
		g_info.no = ft_strtrim(line + 3, " ");
		free_str_array(str);
		g_info.ret++;
		fd = open(g_info.no, O_RDONLY);
		if (fd == -1)
			ft_puterror("Invalid File HHHH", str);
	}
	else
		ft_puterror("Invalid Coordinates Of Nord Texture!", str);
}

void	ft_getwestpath(char *line, int j)
{
	int		fd;
	char	**str;

	str = ft_split(line, ' ');
	while (str[j])
		j++;
	if (j == 2)
	{
		g_info.we = ft_strtrim(line + 3, " ");
		free_str_array(str);
		g_info.ret++;
		fd = open(g_info.we, O_RDONLY);
		if (fd == -1)
			ft_puterror("Invalid File HHHH", str);
	}
	else
		ft_puterror("Invalid Coordinates Of West Texture!", str);
}

void	ft_geteastpath(char *line, int j)
{
	int		fd;
	char	**str;

	str = ft_split(line, ' ');
	while (str[j])
		j++;
	if (j == 2)
	{
		g_info.ea = ft_strtrim(line + 3, " ");
		free_str_array(str);
		g_info.ret++;
		fd = open(g_info.ea, O_RDONLY);
		if (fd == -1)
			ft_puterror("Invalid File HHHH", str);
	}
	else
		ft_puterror("Invalid Coordinates Of East Texture!", str);
}

void	ft_getpaths(char	*line)
{
	int		j;
	char	**str;

	j = 0;
	str = NULL;
	if (!(strncmp(line, "NO ", 3)))
		ft_getnorthpath(line, j);
	else if (!(strncmp(line, "SO ", 3)) && !g_info.so)
		ft_getsouthpath(line, j);
	else if (!(strncmp(line, "WE ", 3)))
		ft_getwestpath(line, j);
	else if (!strncmp(line, "EA ", 3))
		ft_geteastpath(line, j);
	else if (!(strncmp(line, "S ", 2)) && !g_info.s)
		ft_getspath(line, str, j);
	else
		ft_puterror("Invalid File!", NULL);
}
