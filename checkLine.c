/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:07:33 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 13:59:37 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

int	ft_lineisdigit(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (!(ft_isdigit(str[i][j])))
				ft_puterror("Invalid Coordinates!", NULL);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

void	ft_checkndigits(char **str)
{
	if (ft_lineisdigit(str + 1) != 2)
		ft_puterror("Invalid Coordinates Of Resolution!!", str);
	g_info.xR = ft_atoi(str[1]);
	g_info.yR = ft_atoi(str[2]);
	if (g_info.xR <= 0 || g_info.yR <= 0)
		ft_puterror("Invalid Coordinates Of Resolution!! Negative or 0", str);
	if (g_info.xR > 2560)
		g_info.xR = 2560;
	if (g_info.yR > 1440)
		g_info.yR = 1440;
	g_info.ret++;
}

void	ft_getresolution(char *line, int i, char **str)
{
	if (line[i] == ' ' || line[i] == '\t')
	{
		i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (ft_isdigit(line[i]))
		{
			str = ft_split(line, ' ');
			ft_checkndigits(str);
			free_str_array(str);
		}
		else
			ft_puterror("Invalid Coordinates Of Resolution!!", NULL);
	}
	else
		ft_puterror("INVALID FILE, Resolution ERROR!!!", NULL);
}

void	ft_checkline(char *line)
{
	int		k;
	char	**str;

	k = 0;
	str = NULL;
	while (line[k] == ' ' || line[k] == '\t')
		k++;
	if (line[0] == 'R' && !g_info.xR)
		ft_getresolution(line, 1, str);
	else if ((line[0] == 'N' && !g_info.no) || line[0] == 'S'
		|| (line[0] == 'W' && !g_info.we) || (line[0] == 'E' && !g_info.ea))
		ft_getpaths(line);
	else if ((line[0] == 'F' && !g_info.f.red)
		|| (line[0] == 'C' && !g_info.c.red))
		ft_getcolors(line);
	else if (g_info.var == 1 && line[k] == '1')
		ft_puterror("Check Your Map!", NULL);
	else if (line[k] == '1' && g_info.ret == 8)
		schline(0, line, 0);
	else if (g_info.mapheight && line[0] == '\0')
		g_info.var = 1;
	else if (line[0] != '\0')
		ft_puterror("Invalid File!", NULL);
}
