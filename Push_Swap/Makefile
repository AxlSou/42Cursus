# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:12:45 by asoubiel          #+#    #+#              #
#    Updated: 2024/06/18 21:37:18 by asoubiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

CFILES = ft_push.c ft_rotate.c ft_swap.c push_swap.c ft_checks.c ft_reverse_rotate.c \
ft_max_number.c lst_utils.c ft_set_position.c ft_set_index.c ft_move_to_b.c \
ft_sizelst.c ft_sort_three.c ft_set_target_pos.c ft_set_cost.c ft_get_position.c ft_rotation_sort.c \
ft_sort.c ft_error.c ft_atol.c

OFILES = $(CFILES:.c=.o)

LIBFTDIR = libft

LIBFT = ./libft/libft.a

NAME = push_swap

#Rules
all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME) $(LIBFT)

re: fclean $(NAME)

bonus: $(OBONUS)
	ar rcs $(NAME)

.PHONY: all clean fclean re bonus