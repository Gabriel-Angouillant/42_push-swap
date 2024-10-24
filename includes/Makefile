NAME = libft.a
CC = cc
SRCS = ft_printf/ft_printf.c ft_printf/print_char.c ft_printf/print_hex.c ft_printf/print_int.c ft_printf/ft_putchar_fd.c ft_printf/ft_putstr_fd.c ft_printf/ft_strlen.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
