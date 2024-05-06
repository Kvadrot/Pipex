# Compiler
CC = gcc
# Compiler flags
# CFLAGS = -Wall -Wextra -Werror -I./lib_ft
CFLAGS = -I./lib_ft -I./lib_ft_printf
# Sources
SRCS = support_funcs.c \
	   print_errors.c \
	   validating_funcs.c \
	   pipex.c
# Objects
OBJS = $(SRCS:.c=.o)
# Programm Name
NAME = pipex
# Libft src
LIBFT = ./lib_ft/libft.a
# ft_printf
FTPRINTF = ./lib_ft_printf/libftprintf.a

# Main rule / Default
all: $(LIBFT) $(FTPRINTF) $(NAME)

# make lib_ft
$(LIBFT):
	make -C lib_ft

# make lib_ft_printf
$(FTPRINTF):
	make -C lib_ft_printf

# Compile files 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./lib_ft -lft -L./lib_ft_printf -lftprintf

# Clean up obj files
clean:
	make -C lib_ft clean
	make -C lib_ft_printf clean
	rm -f $(OBJS)

#Full clena up
fclean: clean
	make -C lib_ft fclean
	make -C lib_ft_printf fclean
	rm -f $(NAME)

# Rebuild
re:
	fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONE: all clean fclean re