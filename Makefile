NAME		=	cub3d

SRC			=	$(addprefix src/, main.c init_game.c utils.c parse_file.c move_player.c \
					player_utils.c map.c end_game.c)

OBJ			= $(SRC:.c=.o)

LIBFT_PATH	= libft/

LIBFT_NAME	= libft.a

LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

CC			=	cc

RM 			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
