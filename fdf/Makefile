# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagirard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 23:32:30 by lagirard          #+#    #+#              #
#    Updated: 2017/10/22 23:51:18 by lagirard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = srcs/

SRCS = keycode.c bresenham.c main.c colors.c get_map.c verif_map.c\
				draw_map.c free_tabs.c ft_size_win.c ft_proj.c ft_isvalid.c ft_convert.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ -I./libft/includes

LIB = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	    	@make -C libft/
			@make -C minilibx_macos
		  	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o: $(SRC_PATH)%.c
	       	@gcc -c $(FLAGS) $< -o $@ $(INC)

clean :
	        @rm -rf $(OBJ)

fclean : clean
	        @rm -rf $(NAME)
			    @make -C libft fclean
				@make -C minilibx_macos clean

re : fclean all
