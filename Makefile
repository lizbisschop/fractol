# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lbisscho <lbisscho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/22 08:46:37 by lbisscho      #+#    #+#                  #
#    Updated: 2021/10/28 15:33:16 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c pixel_put.c which_fractol.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c julia.c mandelbrot.c

HEADERS = -I fractol.h -I ./libft/libft.h -I ./gnl/get_next_line.h

LIBFT = ./libft


OBJ = $(SRCS:.c=.o)

MLX = ./mlx

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	make -C $(LIBFT)
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	cp ./libft/libft.a ./libft.a
	gcc $(FLAGS) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit \
	$(OBJ) libft.a -o $(NAME)
%.o: %.c %./gnl/.c
	gcc $(FLAGS) -I ./mlx -I libft.a -c $< -o $@
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(MLX)
fclean: clean
	rm -rf $(NAME)
	rm -rf libmlx.dylib
	rm -rf libft.a
	make fclean -C $(LIBFT)
re: fclean all