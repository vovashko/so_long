NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX_PATH = ./mlx

MLX_LIB = $(MLX_PATH)/libmlx.a

FT_PRINTF_PATH = ./ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a

LIBFT_PATH = ./libft

LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS = 	moves.c init_data.c check_path.c check_rules.c \
		utils.c fill_map.c init_map.c so_long.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_LIB) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH)

$(MLX_LIB):	
	make -C $(MLX_PATH)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS) 
	make -C $(FT_PRINTF_PATH) clean 
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	
fclean: clean
	rm -f $(NAME) 
	make -C $(FT_PRINTF_PATH) fclean 
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re