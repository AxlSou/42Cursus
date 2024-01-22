CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_printf.c ft_print_arg.c ft_printchr.c ft_printnbr_base.c ft_printnbr.c ft_printptr.c\
ft_printstr.c

OFILES = $(CFILES:.c=.o)

LIBFTDIR = ./libft

LIBFT = ./libft/libft.a

NAME = libftprintf.a

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

.PHONY:  all clean fclean re