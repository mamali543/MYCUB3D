/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:35:16 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 14:47:21 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy2(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*fct(char *save, char **line)
{
	char	*str;

	str = NULL;
	if (save)
	{
		str = ft_strchr(save, '\n');
		if (str)
		{
			*str = '\0';
			*line = ft_strdup(save);
			ft_strcpy2(save, ++str);
		}
		else
		{
			*line = ft_strdup(save);
			save = NULL;
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (str);
}

void	fct3(char *buff, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	free(tmp);
}

int	fct2(char **save, char *buff, int fd, char **line)
{
	int		size_read;
	char	*str;

	str = fct(*save, line);
	while (!str)
	{
		size_read = (read(fd, buff, BUFFER_SIZE));
		if (size_read == 0)
		{
			zhelper(&buff, save);
			return (0);
		}
		*(buff + size_read) = '\0';
		str = ft_strchr(buff, '\n');
		if (str)
		{
			*str++ = '\0';
			free(*save);
			*save = ft_strdup(str);
		}
		fct3(buff, line);
	}
	free(buff);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;

	if ((read(fd, NULL, 0) != 0) || fd < 0)
		return (-1);
	if (BUFFER_SIZE >= 2147483647 || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	return (fct2(&save, buff, fd, line));
}
