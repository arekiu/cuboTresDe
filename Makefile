# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:49:39 by jjs               #+#    #+#              #
#    Updated: 2025/04/03 16:39:40 by jslusark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[0;31m
GRAY = \033[0;90m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
RESET = \033[0;97m
ORANGE = \033[38;5;208m


# Libraries
LIBFT_PATH	= libft/

LIBFT_NAME	= libft.a

LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)
# Compiler flags and commands
CFLAGS		=	-Wall -Wextra -Werror -g #added g for debugging with gdb
MLX_FLAGS	=	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
RM = rm -rf

SRC_DIR = src
PARSE_DIR = src/parsing
RAY_DIR = src/ray_casting

SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/end_game.c \
	$(RAY_DIR)/init_game.c \
	$(RAY_DIR)/utils.c \
	$(RAY_DIR)/move_player.c \
	$(RAY_DIR)/player_utils.c \
	$(RAY_DIR)/map.c \
	$(RAY_DIR)/ray_casting.c \
	$(PARSE_DIR)/parse_assets.c \
	$(PARSE_DIR)/file_parsing.c \
	$(PARSE_DIR)/collect_map_data.c \
	$(PARSE_DIR)/collect_map_env.c \
	$(PARSE_DIR)/parsing_debugger.c \
	$(PARSE_DIR)/parse_textures.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Compile object files (universal rule for any .c path)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


# Executable name
NAME = cub3d

# Default target
all: $(LIBFT) $(NAME)
	@echo "$(ORANGE)$(NAME)$(RESET) Cub3d is up to date"

# Compile libft only if needed
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

# Compile the main executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(LIBFT)
	@echo "$(ORANGE)$(NAME)$(RESET) compiled successfully"

# Clean object files
clean:
	@if ls $(LIBFT_PATH)/src/*.o >/dev/null 2>&1; then \
		$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean; \
		echo "$(MAGENTA)libft.a$(RESET) object files were removed"; \
	else \
		echo "$(MAGENTA)libft.a$(RESET) object files were already removed"; \
	fi
	@if [ -d $(OBJ_DIR) ]; then \
		$(RM) $(OBJ_DIR); \
		echo "$(ORANGE)$(NAME)$(RESET) object files removed"; \
	else \
		echo "$(ORANGE)$(NAME)$(RESET) object files were already removed"; \
	fi


# Full clean
fclean: clean
	@if [ -f $(LIBFT) ]; then \
		$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean; \
		echo "$(MAGENTA)libft.a$(RESET) library removed"; \
	else \
		echo "$(MAGENTA)libft.a$(RESET) library was already removed"; \
	fi
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(ORANGE)$(NAME)$(RESET) executable removed"; \
	else \
		echo "$(ORANGE)$(NAME)$(RESET) executable was already removed"; \
	fi

# Recompile everything
re: fclean all
	@echo "$(ORANGE)$(NAME)$(RESET) successfully recompiled $(RESET)"

%:
	@echo "$(RED)Failure:$(RESET) target '$@' is not a valid target."
	@echo "Please use one of the following valid targets:"
	@echo "- $(GREEN)make$(RESET): compiles the project"
	@echo "- $(GREEN)make re$(RESET): recompiles the project"
	@echo "- $(GREEN)make clean$(RESET): removes object files"
	@echo "- $(GREEN)make fclean$(RESET): removes object files and the final binary"

.PHONY: all clean fclean re %
