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
		tcheck_piece.c\
		free_all.c
NORMAL = init_and_determine.c\
		main.c\
		filler.c\

COLOR = color_filler.c\
		main.c\
		filler.c\

TRANKIL = init_and_determine.c\
		ajust_trankil.c\
		filler.c\

COLOR_TRANKIL = color_filler.c\
				ajust_trankil.c\
				filler.c\

OTHER_ALGO = main.c\
			init_and_determine.c\
			filler_other_algo.c\
			determine_y1_x1.c

TRANKIL_OTHER_ALGO	 = ajust_trankil.c\
					init_and_determine.c\
					filler_other_algo.c\
					determine_y1_x1.c

COLOR_OTHER_ALGO = main.c\
				color_filler.c\
				filler_other_algo.c\
				determine_y1_x1.c

COLOR_TRANKIL_OTHER_ALGO = ajust_trankil.c\
						color_filler.c\
						filler_other_algo.c\
						determine_y1_x1.c

LIB	= -L libft -lft

all:	$(NAME)
	@printf "Program is compiled.\n"
$(NAME):
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(NORMAL) $(LIB) -o $(NAME) 
	
color: 
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(COLOR) $(LIB) -o $(NAME) 

trankil:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(TRANKIL) $(LIB) -o $(NAME)

color_trankil:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(COLOR_TRANKIL) $(LIB) -o $(NAME)

other_algo:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(OTHER_ALGO) $(LIB) -o $(NAME)

trankil_other_algo:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(TRANKIL_OTHER_ALGO) $(LIB) -o $(NAME)

color_other_algo:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(COLOR_OTHER_ALGO) $(LIB) -o $(NAME)

color_trankil_other_algo:
	@make -C libft
	@gcc -g $(CFLAGS) $(FILES) $(COLOR_TRANKIL_OTHER_ALGO) $(LIB) -o $(NAME)

clean:
	make -C libft clean
	@$(RM) .obj

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

norme:
	norminette $(FILES) $(COLOR) $(TRANKIL) filler.h

.PHONY: all make_libft clean fclean re norme color trankil color_trankil\
	other_algo trankil_other_algo color_trankil_other_algo