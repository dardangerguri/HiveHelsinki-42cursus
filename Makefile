# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 16:24:12 by dgerguri          #+#    #+#              #
#    Updated: 2023/06/11 14:51:05 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_D = ./libft
LIBFT = ./libft/libft.a

INCLUDE = -I ./includes/

SRC_DIR = ./srcs/
SRC_BONUS_DIR = ./srcs_bonus/

SRC =	main.c \
		pipex.c \
		error.c \
		pipex_split.c


SRC_BONUS =	main_bonus.c \
			pipex_bonus.c \
			error_bonus.c \
			pipex_here_doc.c \
			pipex_split_bonus.c


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
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L $(LIBFT_D) -lft

bonus: all $(BONUS_DONE)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DONE): $(OBJ_BONUS)
	@echo "$(BLUE)Compiling $(NAME) bonuses! $(RESET)"
	@$(MAKE) -C $(LIBFT_D)
	@$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME) -L $(LIBFT_D) -lft
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
