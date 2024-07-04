# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 23:51:52 by asoubiel          #+#    #+#              #
#    Updated: 2024/07/04 19:07:41 by asoubiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
CLIENT_NAME = client
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
COMMON_SRCS = error_handlers.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)
LIBFTDIR = libft
LIBFT = ./libft/libft.a

# Rules
all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(CLIENT_NAME)

clean:
	make clean -C $(LIBFTDIR)
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(COMMON_OBJS)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(COMMON_OBJS) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re