/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:47:05 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 17:49:15 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	plombier(int strip_id, float ray_angle)
{
	g_info.g_rays[strip_id].ray_angle = ray_angle;
	g_info.g_rays[strip_id].down = ray_angle > 0 && ray_angle < M_PI;
	g_info.g_rays[strip_id].up = !g_info.g_rays[strip_id].down;
	g_info.g_rays[strip_id].right = ray_angle < (M_PI / 2)
		|| ray_angle > (1.5 * M_PI);
	g_info.g_rays[strip_id].left = !g_info.g_rays[strip_id].right;
}

void	ft_checkan(int argc)
{
	if (argc > 3 || argc < 2)
		ft_puterror("you should have at least 2 or 3 arguments!", NULL);
}

void	ft_checkeof(char *argv)
{
	char	*p;

	p = ft_strrchr(argv, '.');
	if (!p)
		ft_puterror("Invalid Extension\n", NULL);
	if ((ft_strncmp(p, ".cub", 4)))
		ft_puterror("Invalid Extension\n", NULL);
}

int	ft_checksa(char *argv)
{
	if (argv && (strncmp(argv, "--save", ft_strlen(argv))))
		ft_puterror("ERROR", NULL);
	else
		return (1);
	return (0);
}

void	ft_checkargs(int argc, char **argv)
{
	ft_checkan(argc);
	ft_checkeof(argv[1]);
	ft_checksa(argv[2]);
}
