# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Sources
SRCS = support_funcs.c \
	   pipex.c

# Objects
OBJS = $(SRCS:.c=.o)

# Programm Name
NAME = pipex

# Main rule / Default
all: $(NAME)

# Compile files 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean up obj files
clean:
	rm -f $(OBJS)

# Full clean up
fclean:
	rm -f $(NAME)

# Rebuild
re:
	fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONE: all clean fclean re