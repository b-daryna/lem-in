# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2017/11/24 12:57:33 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	lem-in

VISUAL = visu-hex

LIBFT = ./libft/libft.a

PRINTF = ./libft/ft_printf/libftprintf.a

SRC1 = 	main.c \
        read_input.c \
        validity.c \
        output.c \
        helpers.c \
        create_rooms.c \
        create_links.c \
        move_ants.c \

SRC2 = 	vis/visual.c \
        vis/create_data.c \
        vis/helpers.c \
        vis/link_helpers.c \
        vis/mlx.c \
        vis/draw.c \
        vis/draw_links.c \
        vis/move.c \

FLAGS = -Wall -Wextra -Werror

OBJ1  = $(SRC1:.c=.o)

OBJ2  = $(SRC2:.c=.o)

all     : $(NAME) $(VISUAL)

$(NAME) : $(OBJ1) $(LIBFT) $(PRINTF)
	    gcc $(FLAGS) $(OBJ1) -o $(NAME) $(LIBFT) $(PRINTF)

$(VISUAL) : $(OBJ2) $(LIBFT) $(PRINTF)
	    gcc $(FLAGS) $(OBJ2) -o $(VISUAL) $(LIBFT) $(PRINTF)\
        			        -O3 -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $<

$(LIBFT)  :
	    make -C libft/

$(PRINTF)  :
	    make -C libft/ft_printf/
	    make -C libft/ft_printf/ clean

lclean  :
	    make -C libft/ clean

clean   : lclean
	    rm -f $(OBJ1)
	    rm -f $(OBJ2)

fclean  : clean
	    rm -f $(NAME) $(VISUAL)
		rm -f libft/libft.a
		rm -f libft/ft_printf/libftprintf.a

re: fclean all
