# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoupart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 10:08:38 by atoupart          #+#    #+#              #
#    Updated: 2016/08/02 10:42:30 by lsimonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc -g
RM		= /bin/rm -rf

SRCS	= ft_atoi.c\
		ft_atoi_b.c\
		ft_bzero.c\
		ft_ishexa.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isspace.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putlnbr.c\
		ft_putstr.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strdup_f.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_tolower.c\
		ft_strtolower.c\
		ft_strtoupper.c\
		ft_toupper.c\
		ft_memalloc.c\
		ft_putendl.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strsub.c\
		ft_strsub_f.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strjoin_f.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putlnbr.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_uitoa_base.c\
		ft_strsplit.c\
		ft_lstnew.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		#get_next_line.c\
		ft_error.c\
		ft_printf.c\
		conv_funcs.c\
		conv_funcs2.c\
		transform.c\
		transform2.c\
		parse_fmt.c\
		split_fmt.c\
		padding.c\
		padding2.c\
		ft_strndup.c

CFLAGS	= -Wall -Wextra -Werror

INC		= ./
OBJ		= ${SRCS:%.c=.obj/%.o}
FTO		= $(FTC:.c=.o)

all: $(NAME)
	@printf ""

$(NAME): $(OBJ)
		@echo ""
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "création de $(NAME)"

.obj/%.o: %.c
	@mkdir -p .obj
	@$(CC) $(CFLAGS) -c $< -o $@  -I $(INC)
	@printf .

clean:
		@$(RM) .obj

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
