# Project Name
NAME	= push_swap

# Compiler and Flags
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Iincludes -Ift_printf/includes

# Folders
SRC_DIR	= srcs
UTILS_DIR	= srcs/utils
OBJ_DIR	= obj
PRINTF_DIR	= ft_printf

# Source Files
UTILS_SRCS	= calcul_cost.c calcul_target.c calculate_b_s.c ft_split.c \
			  lst_utils.c push.c reverse_rotate.c rotate.c swap.c
MAIN_SRCS	= main.c algo.c end_algo.c push_swap.c

# Add prefixes to source files
UTILS_SRCS	:= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
MAIN_SRCS	:= $(addprefix $(SRC_DIR)/, $(MAIN_SRCS))

# Combine all source files
SRCS	= $(UTILS_SRCS) $(MAIN_SRCS)

# Object Files
OBJS	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Libftprintf
LIBFT	= $(PRINTF_DIR)/libftprintf.a

# Build Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re