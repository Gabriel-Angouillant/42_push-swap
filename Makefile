NAME = push_swap
CC = cc
SRCS = srcs/index_stack.c \
	srcs/small_stacks.c \
	srcs/parsing.c \
	srcs/sort.c \
	srcs/stack_create.c \
	srcs/main.c \
	srcs/args_to_char.c \
	srcs/operations/push.c \
	srcs/operations/swap.c \
	srcs/operations/rotate.c \
	srcs/operations/r_rotate.c

INCLUDES = includes/libft.a
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C includes/ all
	@$(CC) $(FLAGS) $^ $(INCLUDES) -o $(NAME)
	@echo "\033[1;32m -= Sources compiled =-"

%.o: %.c
	@$(CC) $(FLAGS) $< -c -o $@

clean:
	@make -s -C includes/ clean
	@rm -f $(OBJS)
	@echo "\033[1;31m -= Sources removed =-"

fclean: clean
	@make -s -C includes/ fclean
	@rm -f $(NAME)
	@echo "\033[1;31m -= Executable removed =-"

re: fclean all
