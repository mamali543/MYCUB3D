/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:32:47 by mamali            #+#    #+#             */
/*   Updated: 2019/10/23 23:13:30 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	s = malloc((len + 1) * sizeof(char));
	if (s == 0)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
