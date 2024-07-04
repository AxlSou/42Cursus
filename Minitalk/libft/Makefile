CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalnum.c\
ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c\
ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_print_arg.c ft_printchr.c ft_printnbr_base.c \
ft_printnbr.c ft_printptr.c ft_printstr.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c ft_print_arg.c ft_printchr.c ft_printnbr_base.c ft_printnbr.c \
ft_printptr.c ft_printstr.c ft_printf.c

OFILES = $(CFILES:.c=.o)

NAME = libft.a

#Rules
all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re bonus