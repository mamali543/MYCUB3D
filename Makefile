NAME		=		cub3D

SRCS		=		mapallocation.c\
					utils.c\
					utils2.c\
					sprite.c\
					renderwall.c\
					readfile.c\
					plombier.c\
					main.c\
					init.c\
					getPaths.c\
					getMap.c\
					get_colors.c\
					checkLine.c\
					check_args.c\
					cast_rays.c\
					bmp.c\

LIBFT 		= 		./mylibft/libft.a

INCLUDE = -I ./mylibft/libft.h -I ./include/cub3D.h -I /usr/local/include

GCC = gcc -Wall -Wextra -Werror -g
MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	make -C mylibft
	$(GCC) $(INCLUDE) $(SRCS)  $(LIBFT) $(MLX) -o $(NAME)
clean:
	rm -rf mylibft/*.o
	rm -rf mylibft/libft.a

fclean: clean
	rm -rf $(NAME)
re: fclean all