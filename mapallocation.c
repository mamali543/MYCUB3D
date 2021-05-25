/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapallocation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:34:50 by mamali            #+#    #+#             */
/*   Updated: 2021/05/08 10:36:32 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

char	**ft_realloc(char **s, char *p, int i, int len)
{
	int		k;
	char	*d;
	char	**str;

	len = tablen(s);
	str = (char **)malloc(sizeof(char *) * (len + 2));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = ft_strdup(s[i]);
		i++;
	}
	free_str_array(s);
	k = g_info.maplwidth - ft_strlen(p);
	d = malloc(sizeof(char *) * (k + 1));
	if (!d)
		return (NULL);
	d = ft_memset((void *)d, ' ', k);
	d[k] = '\0';
	str[i++] = ft_strjoin(p, d);
	free(p);
	free(d);
	str[i] = NULL;
	return (str);
}
