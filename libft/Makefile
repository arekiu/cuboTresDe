# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 12:06:22 by aschmidt          #+#    #+#              #
#    Updated: 2025/03/26 13:37:24 by jslusark         ###   ########.fr        #
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

SRC	= $(addprefix src/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	  ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
	  ft_print.c ft_pointer.c ft_unsigned.c ft_printcds.c)

OBJS	:= $(SRC:%.c=%.o)

NAME	= libft.a

CC 	= cc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "$(MAGENTA)$(NAME)$(RESET) is up to date"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(MAGENTA)$(NAME)$(RESET) compiled successfully"

%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $<

#rm -f force in case the file doesnt exist
clean:
	@rm -f $(OBJS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all
	echo "$(WARNING) $(MAGENTA)$(NAME)$(RESET) has been recompiled succelly"

.PHONY: all clean fclean re
