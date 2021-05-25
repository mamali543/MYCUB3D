/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:17:15 by mamali            #+#    #+#             */
/*   Updated: 2019/10/22 23:59:41 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (*(to_find) == 0)
		return ((char *)s);
	while (s[i] && (i < len))
	{
		j = 0;
		while (s[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
