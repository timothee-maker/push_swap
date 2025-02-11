NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Iinclude -Ift_printf/includes
SRC_DIR	= srcs
OBJ_DIR	= obj
PRINTF_DIR = ft_printf
LIBFT_DIR = libft
SRCS = calcul_cost.c calcul_target.c calculate_b_s.c \
       lst_utils.c push.c reverse_rotate.c rotate.c swap.c \
       main.c algo.c end_algo.c push_swap.c parse.c handle_element.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIBFT	= $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
