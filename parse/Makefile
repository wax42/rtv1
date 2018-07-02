# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 22:43:05 by vguerand          #+#    #+#              #
#    Updated: 2018/06/04 22:35:17 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_atoi.c ft_isdigit.c ft_strcat.c ft_strchr.c ft_strdel.c ft_strdup.c\
	ft_strjoin.c ft_strnjoin.c ft_strlen.c ft_strcat.c ft_strncat.c get_next_line.c\
	ft_strnew.c ft_strstr.c ft_memalloc.c ft_memset.c ft_strcpy.c ft_strndup.c \
	ft_strncpy.c ft_memcpy.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_putendl.c

SRC_PATH = libft/

OBJ = $(patsubst %.c,%.o, $(addprefix $(SRC_PATH), $(SRC_NAME)))

CC = gcc

.SILENT:

CFLAGS = -Wall -Werror -Wextra

FLAGMLX = -framework OpenGL -framework Appkit

HEAD	= include/libft.h

all : $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		@echo "\033[0;32m[OK] \033[0m\033[0;33m Compiling file:\033[0m " $@
clean:
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m libft" $@
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m libft " $@
	@/bin/rm -f $(NAME)

re : fclean all
