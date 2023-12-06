NAME = so_long
CC = cc
CFLAGS = -Wextra -Werror -Wall -g
LINKS_LINUX = -lX11 -lm -lXext
RM = rm -f

MINILIBX = libx/libmlx.a
LIBFT = libft_extended/libft.a
PRINTF = ft_printf/libftprintf.a

SRC = management.c \
map_management.c \
image_management.c \
utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib_comp mlx_comp comp

lib_comp:
	make -C libft_extended/
mlx_comp:
	make -C libx/
printf_comp:
	make -c ft_printf/

comp:
	$(CC) $(CFLAGS) $(LINKS_LINUX) $(SRC) $(LIBFT) $(MINILIBX) $(PRINTF) -o $(NAME)

comp_linux:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C libx/
	make clean -C libft_extended/
	$(RM) $(NAME)

re: fclean all