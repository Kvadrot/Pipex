# Compiler
CC = gcc
# Compiler flags
# CFLAGS = -Wall -Wextra -Werror -I./lib_ft
CFLAGS = -I./lib_ft
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

# Main rule / Default
all: $(LIBFT) $(NAME)

# make lib_ft
$(LIBFT):
	make -C lib_ft

# Compile files 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./lib_ft -lft

# Clean up obj files
clean:
	make -C lib_ft clean
	rm -f $(OBJS)

#Full clena up
fclean: clean
	make -C lib_ft fclean
	rm -f $(NAME)

# Rebuild
re:
	fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONE: all clean fclean re