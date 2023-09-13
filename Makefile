# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:24:12 by dgerguri          #+#    #+#              #
#    Updated: 2023/09/11 13:44:43 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT_D = ./libft
LIBFT = ./libft/libft.a

INCLUDE = -I ./includes/

SRC_DIR = ./srcs/
SRC_BONUS_DIR = ./srcs_bonus/

SRC = 	main.c \
		read_and_save.c \
		file_validation.c \
		map_validation.c \
		map_validation_utils.c \
		game_initialization.c \
		key_input.c \
		moving.c \
		error.c

SRC_BONUS = main_bonus.c \
		read_and_save_bonus.c \
		file_validation_bonus.c \
		map_validation_bonus.c \
		map_validation_utils_first_bonus.c \
		map_validation_utils_second_bonus.c \
		game_initialization_bonus.c \
		key_input_bonus.c \
		moving_bonus.c \
		moving_utils_bonus.c \
		error_bonus.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS_DIR = obj_bonus/
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(SRC_BONUS:.c=.o))
BONUS_DONE = $(OBJ_BONUS_DIR).done

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
	@$(CC) $(FLAGS) $(MLX) $(OBJ) -o $(NAME) -L $(LIBFT_D) -lft

bonus: $(BONUS_DONE)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DONE): $(OBJ_BONUS)
	@echo "$(BLUE)Compiling $(NAME) bonuses! $(RESET)"
	@$(MAKE) -C $(LIBFT_D)
	@$(CC) $(FLAGS) $(MLX) $(OBJ_BONUS) -o $(NAME) -L $(LIBFT_D) -lft -fsanitize=address
	@touch $(BONUS_DONE)

clean:
	@$(MAKE) clean -C $(LIBFT_D)
	@$(RM) -r $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "$(RED)Removed object files from $(NAME)!$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_D)
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)!$(RESET)"

re:fclean all

.PHONY: all clean fclean re bonus
