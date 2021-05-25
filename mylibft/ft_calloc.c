/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:16:53 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 13:49:37 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	long	i;

	i = count * size;
	p = malloc(i);
	if (!p)
		return (0);
	while (i--)
		p[i] = 0;
	return (p);
}
