# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoupart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 14:25:49 by atoupart          #+#    #+#              #
#    Updated: 2016/08/25 14:25:51 by atoupart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= atoupart.filler

RM		= /bin/rm -rf

CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address

FILES	= \
		filler.c\
		recursive_point.c\
		search_position.c\
		search_position2.c\
		fonctions_tool.c\
		find_point_player.c\
		find_point_player2.c\
		find_point_opponent.c\
		find_point_opponent2.c\
		orientation_piece.c\
		search.c\
		parcour_point.c\
		tool_parcour_search.c\
		verif_rim.c\
		carli_style.c\
		tcheck_piece.c

COLOR = color_filler.c
		
NORMAL = init_and_determine.c

LIB = ./libft/libft.a
#LIB	= -L libft -lft

all:	$(NAME)
	@printf "Program is compiled.\n"
$(NAME):
	# @make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(NORMAL) $(LIB) -o $(NAME) 
	
color: 
	# @make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(COLOR) $(LIB) -o $(NAME) 

clean:
	# make -C libft clean
	@$(RM) .obj

fclean: clean
	# make -C libft fclean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(FILES) filler.h
function:
	nm -u $(NAME)

.PHONY: all make_libft clean fclean re norme