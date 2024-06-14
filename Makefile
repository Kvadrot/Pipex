# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I./lib_ft -I./lib_ft_printf -I./get_next_line_final
LDFLAGS = -L./lib_ft -lft -L./lib_ft_printf -lftprintf -L./get_next_line_final -l:gnl.a

# Default sources
SRCS = pipex.c utilities.c sup_utilities.c
OBJS = $(SRCS:.c=.o)

# Bonus sources
SRCS_BONUS = pipex_bonus.c utilities.c sup_utilities.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Program Name
NAME = pipex
BONUS_NAME = pipex_bonus

# Libft src
LIBFT = ./lib_ft/libft.a

# ft_printf
FTPRINTF = ./lib_ft_printf/libftprintf.a

# get_next_line
GNL = ./get_next_line_final/gnl.a

# Default rule
all: $(LIBFT) $(FTPRINTF) $(GNL) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

# Bonus rule
bonus: $(LIBFT) $(FTPRINTF) $(GNL) $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(LDFLAGS)

# Make lib_ft
$(LIBFT):
	make -C lib_ft

# Make lib_ft_printf
$(FTPRINTF):
	make -C lib_ft_printf

# Make GNL
$(GNL):
	make -C get_next_line_final

# Clean up obj files
clean:
	make -C lib_ft clean
	make -C lib_ft_printf clean
	make -C get_next_line_final clean
	rm -f $(OBJS) $(OBJS_BONUS)

# Full clean up
fclean: clean
	make -C lib_ft fclean
	make -C lib_ft_printf fclean
	make -C get_next_line_final fclean
	rm -f $(NAME) $(BONUS_NAME)

# Rebuild
re: fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONY: all clean fclean re bonus
