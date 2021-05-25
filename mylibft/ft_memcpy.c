/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:59:46 by mamali            #+#    #+#             */
/*   Updated: 2019/10/26 03:58:53 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dst && !src)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
		((unsigned char *)dst)[j++] = ((unsigned char *)src)[i++];
	return (dst);
}
