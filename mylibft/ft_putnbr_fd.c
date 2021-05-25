/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:48:49 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 13:48:53 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i = -i;
		ft_putchar_fd(45, fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + 48, fd);
	}
	if (i <= 9 && i >= 0)
	{
		ft_putchar_fd(i + 48, fd);
	}
}
