# Compiler
CC = gcc
# Compiler flags
# CFLAGS = -Wall -Wextra -Werror -I./lib_ft
CFLAGS = -I./lib_ft -I./lib_ft_printf -I./get_next_line_final

LDFLAGS = -L./lib_ft -lft -L./lib_ft_printf -lftprintf -L./get_next_line_final -l:gnl.a

# Sources
SRCS = pipex.c
# Objects
OBJS = $(SRCS:.c=.o)
# Programm Name
NAME = pipex
# Libft src
LIBFT = ./lib_ft/libft.a
# ft_printf
FTPRINTF = ./lib_ft_printf/libftprintf.a
# get_next_line
GNL = ./get_next_line_final/gnl.a

# Main rule / Default
all: $(NAME)
$(NAME):	$(LIBFT) $(FTPRINTF) $(GNL) $(NAME)

#Bonus PART
SRCS_BONUS	= ./pipex_bonus.c
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

#Bonus rule
bonus: $(NAME) 
$(NAME):	$(LIBFT) $(FTPRINTF) $(GNL) $(NAME)


# make lib_ft
$(LIBFT):
	make -C lib_ft

# make lib_ft_printf
$(FTPRINTF):
	make -C lib_ft_printf

# make GNL
$(GNL):
	make -C get_next_line_final

# Compile files 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

# Clean up obj files
clean:
	make -C lib_ft clean
	make -C lib_ft_printf clean
	make -C get_next_line_final clean
	rm -f $(OBJS) $(OBJS_BONUS)

#Full clena up
fclean: clean
	make -C lib_ft fclean
	make -C lib_ft_printf fclean
	make -C get_next_line_final fclean
	rm -f $(NAME)

# Rebuild
re:
	fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONE: all clean fclean re