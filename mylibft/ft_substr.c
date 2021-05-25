/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 05:50:09 by mamali            #+#    #+#             */
/*   Updated: 2019/10/28 09:13:47 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	int				i;
	unsigned int	bigg;

	i = 0;
	bigg = start;
	if (!s || start > ft_strlen(s))
	{
		p = malloc(1 * sizeof(char));
		p[0] = '\0';
		return (p);
	}
	p = malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while (start < (unsigned int)len + bigg && s[start])
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
