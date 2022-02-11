# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senam <senam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 22:54:43 by senam             #+#    #+#              #
#    Updated: 2022/02/11 17:30:54 by senam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

#
# SRCS and OBJS
#

SRCS	=	main.c \
			play/key_handling.c play/move.c play/opening_ending.c \
			map/check_map.c map/check_map_utils.c map/parse_map.c map/error.c \
			draw/draw_map.c draw/draw.c init/init1.c init/init2.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra 
CLIB	=	-lmlx -Lmlx -framework OpenGL -framework Appkit -Imlx

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
