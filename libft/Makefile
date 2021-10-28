# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lbisscho <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 13:17:17 by lbisscho       #+#    #+#                 #
#    Updated: 2019/11/14 17:46:34 by lbisscho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_isascii.c ft_memccpy.c ft_memcpy.c ft_strchr.c \
	ft_strlen.c ft_strrchr.c ft_isalnum.c ft_isdigit.c ft_memchr.c \
	ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_atoi.c \
	ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_strlcpy.c \
	ft_strnstr.c ft_toupper.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_calloc.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Wextra -Werror -I . -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
