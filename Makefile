NAME_L = libftprintf.a
NAME = push_swap

CC = cc
C_FLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs
SRCS_L = ft_printf/funcs.c ft_printf/ft_printf.c ft_printf/process_string.c ft_printf/process_string2.c ft_printf/funcs2.c
SRCS = push_swap.c push_swap_operations.c push_swap_utils.c push_swap_sort_stack.c

OBJS_L = $(SRCS_L:%.c=%.o)
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(OBJS_DIR) $(NAME_L) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME_L): $(OBJS_L) # создание библ
	ar rcs $(NAME_L) $(OBJS_L)

$(NAME): $(OBJS) $(NAME_L) # компиляция с уже созданной библиотекой
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS) -L. -lftprintf

$(OBJS_DIR)/%.o: %.c
	$(CC) $(C_FLAGS) -Ift_printf -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_L)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_L)

re: fclean all

.PHONY: all clean fclean re