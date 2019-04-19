# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 16:52:32 by vguerand          #+#    #+#              #
#    Updated: 2019/01/04 15:19:54 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	rtv1

#==============================================================================#
#------------------------------------------------------------------------------#
#                               DIRECTORIES                                    #

SRC_DIR			:=	./srcs
PARSER_DIR		:=	parser
MLX_DIR			:=	./mlx_macos
INC_DIR			:=	./includes
OBJ_DIR			:=	./objs
LIB_DIR			:=	./libs

#==============================================================================#
#------------------------------------------------------------------------------#
#                                  FILES                                       #

SRC				:=	main.c					\
							# ft_raytracer.c			\
							# projection.c			\
							# obj_inter.c				\
							# obj_normal.c			\
							# phong.c					\
							# init.c					\
							# raytracing.c			\
							# ray_distorted.c			\
							# gi_ray_distorted.c		\
							# global_illumination.c	\
							# fresnel.c				\
							# get_all_inter.c			\
							# transparent.c			\

SRC_PARSER		:=			parser_json.c			\
							json_key.c				\
							json_val.c				\
							json_utils.c			\
							json_obj_separator.c	\
							get_color.c				\
							take_ptr_vec.c			\
							handle_double.c			\
							handle_string.c			\
							allocation.c			\
							ft_atod.c				\

# OBJ_PARSER	:= $(addprefix $(OBJ_DIR)/,$(SRC_PARSER:.c=.o))

OBJ			:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# SRC_ALL		:= $(SRC_PARSER)
SRC_ALL		:= $(SRC)

NB			:= $(words $(SRC_ALL))
INDEX		:= 0

#==============================================================================#
#------------------------------------------------------------------------------#
#                            COMPILER & FLAGS                                  #

CC			:=		gcc
CFLAGS		:=		-Wall -Wextra -Werror
CFLAGS		+=		-g3
CFLAGS		+=		-O2
MLXFLAGS	:=		-framework OpenGL -framework AppKit


#==============================================================================#
#------------------------------------------------------------------------------#
#                                LIBRARY                                       #

# Library de mort demander a smoskthar ou il s'en sert dans le code

X = -I/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/



LIBFT			:=			$(LIB_DIR)/libft/libft.a
LIBMATH			:=			$(LIB_DIR)/libmath/libmaths.a
CLIB			:=			-L$(LIB_DIR)/libft -lft
LIB_MLX			:=			$(MLX_DIR)/libmlx.a

#==============================================================================#
#------------------------------------------------------------------------------#
#                                 RULES                                        #

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMATH) $(OBJ_DIR) $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(CLIB) $(LIB_MLX) $(LIBMATH)
	@printf '\033[33m[ READY ] %s\n\033[0m' "Compilation of $(NAME) is done ---"

$(LIBFT):
	@make -C $(LIB_DIR)/libft

$(LIBMATH):
	@make -C $(LIB_DIR)/libmath

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) $(CFLAGS) -o $@ -c $< $(X) -I$(INC_DIR)
	@echo "[ %d%% ] %s :: %s        \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR)/libft clean
	@$(MAKE) -C $(LIB_DIR)/libmath clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIB_DIR)/libft fclean
	@$(MAKE) -C $(LIB_DIR)/libmath fclean
	@$(MAKE) -C $(MLX_DIR) fclean
	@echo '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re build cbuild
