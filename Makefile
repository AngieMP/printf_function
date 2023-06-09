SRCS = ft_printf.c print_char.c print_str.c print_nbr.c print_low_hexa.c print_upp_hexa.c ft_strlen.c print_unsigned.c print_ptr.c hexa_len.c

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re