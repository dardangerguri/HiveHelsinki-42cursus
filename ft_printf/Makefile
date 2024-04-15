# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:01:59 by dgerguri          #+#    #+#              #
#    Updated: 2023/09/09 16:05:54 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_D = ./libft
LIBFT = ./libft/libft.a

INCLUDE = -I ./includes/

SRC_DIR = ./srcs/

SRC = 	ft_printf.c \
		unsigned_decimal_printf.c \
		hexadecimal_printf.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME) project! $(RESET)"
	@$(MAKE) -C $(LIBFT_D)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@$(MAKE) clean -C $(LIBFT_D)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Removed object files from $(NAME)!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_D)
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)!$(RESET)"

re:fclean all

.PHONY: all clean fclean re
