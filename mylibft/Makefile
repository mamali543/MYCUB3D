# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamali <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 17:07:33 by mamali            #+#    #+#              #
#    Updated: 2019/10/29 18:54:25 by mamali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

SRCS = ft_calloc.c\
	   ft_memset.c\
	   ft_memcmp.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_strlen.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strncmp.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   get_next_line.c\
	   
OBJS= $(SRCS:%c=%o)
$(NAME): all

all:
	gcc $(FLAGS) $(SRCS)
	ar -rc $(NAME) *.o
	ranlib $(NAME)
linux:
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)
