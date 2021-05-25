/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamali <mamali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:36:26 by mamali            #+#    #+#             */
/*   Updated: 2021/05/07 14:35:04 by mamali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# define BUFFER_SIZE 1024

int		get_next_line(const int fd, char **line);
int		fct2(char **save, char *buff, int fd, char **line);
void	fct3(char *buff, char **line);
char	*fct(char *save, char **line);

#endif
