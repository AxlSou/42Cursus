# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 19:02:17 by asoubiel          #+#    #+#              #
#    Updated: 2024/08/17 21:40:24 by asoubiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#Directories
SRCDIR = src
INCDIR = include
ASSETDIR = assets
LIBSDIR = libs
MLXDIR = $(LIBSDIR)/MLX42
LIBFTDIR = $(LIBSDIR)/Libft

#Includes
INCLUDES = -I $(INCDIR) -I $(MLXDIR)/include

#Libraries
LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFTDIR)/libft.a

#Sources
SRC_FILES = $(SRCDIR)/main.c $(SRCDIR)/init.c $(SRCDIR)/errors.c $(SRCDIR)/load_img.c
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = so_long

#Rules
all: libmlx libft $(NAME)

libmlx:
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

libft:
	@make -C $(LIBFTDIR)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) $(LIBS) -o $(NAME)

clean:
	@make -C $(LIBFTDIR) clean
	@rm -rf $(OBJ_FILES)
	@rm -rf $(MLXDIR)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
