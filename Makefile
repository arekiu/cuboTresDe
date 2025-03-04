NAME		=	cub3d

SRC			=	$(addprefix src/, main.c)

OBJ			=	$(SRC:.c=.o)

LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

MLX_PATH	=	MLX42/
MLX_BUILD	=	$(MLX_PATH)build/
MLX_LIB		=	$(MLX_BUILD)libmlx42.a

CC			=	cc
RM 			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I$(MLX_PATH)include
MLX_FLAGS	=	-L$(MLX_BUILD) -lmlx42 -ldl -lglfw -pthread -lm

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	@cmake -B $(MLX_BUILD) $(MLX_PATH)
	@cmake --build $(MLX_BUILD) -j4

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)
	@rm -rf $(MLX_BUILD)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
