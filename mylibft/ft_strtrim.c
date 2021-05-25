/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:57:36 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 14:20:42 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_i;
int		g_j;

static int	check(char const *str, char se)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == se)
			return (1);
		i++;
	}
	return (0);
}

static int	cal_size(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0')
	{
		if (check(set, s1[i]) == 1)
			i++;
		else
			break ;
	}
	while (j >= 0)
	{
		if (check(set, s1[j]) == 1)
		{
			i++;
			j--;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		size;

	if (!s1)
		return (NULL);
	if (cal_size(s1, set) > (int)ft_strlen(s1))
	{
		tab = malloc(sizeof(char) * (1));
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	size = ft_strlen(s1) - cal_size(s1, set);
	g_i = 0;
	g_j = 0;
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	while (check(set, s1[g_i]) == 1)
		g_i++;
	while (g_j < size)
		tab[g_j++] = (char)s1[g_i++];
	tab[g_j] = '\0';
	return (tab);
}
