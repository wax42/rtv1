# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 15:26:20 by smokhtar          #+#    #+#              #
#    Updated: 2018/06/06 15:26:22 by smokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = rtv1

flag = -Wall -Werror -Wextra

comp = -lmlx -framework OpenGL -framework AppKit

file =main\
	  vecteur\
	  vecteur2\
	  algo\
	  math1\
	  mlxlib\
	  key\

Src = $(addprefix srcs/, $(file))

src = $(addsuffix .c, $(Src))

X = -I/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/

lib = -lmlx -Lminilibx_macos libft/libft.a

inc = -Iincludes -Iminilibx -Ilibft

object = $(addsuffix .o, $(file))

all: $(name)

$(name) :
	make -C minilibx_macos/
	make -C libft/
	gcc -c $(src) $(flag) $(X) $(inc)
	gcc -o $(name) $(lib) $(flag) $(X) $(comp) $(object) $(inc)

clean :
	rm -f $(object)

fclean : clean
	rm -f $(name)

re : fclean all

e :
	rm -f $(name)
	make
