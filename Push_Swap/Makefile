# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:12:45 by asoubiel          #+#    #+#              #
#    Updated: 2024/02/06 16:23:15 by asoubiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_push.c ft_rotate.c ft_swap.c push_swap.c

OFILES = $(CFILES:.c=.o)

LIBFTDIR = libft

LIBFT = ./libft/libft.a

NAME = push_swap

#Rules
all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME) $(LIBFT)

re: fclean $(NAME)

bonus: $(OBONUS)
	ar rcs $(NAME)

.PHONY: all clean fclean re bonus