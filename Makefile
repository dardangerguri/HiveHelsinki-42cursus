# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:08:35 by dgerguri          #+#    #+#              #
#    Updated: 2023/06/12 16:13:00 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

INCLUDE = -I ./includes/

SRC =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strncmp.c ft_striteri.c ft_strdup.c ft_strchr.c ft_strrchr.c ft_strjoin.c ft_strtrim.c\
		ft_substr.c ft_strmapi.c ft_strnstr.c ft_split.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_memcmp.c ft_bzero.c ft_calloc.c ft_memset.c ft_memchr.c ft_memcpy.c ft_memmove.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_atoi.c ft_itoa.c\

SRC_BONUS = ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstmap_bonus.c

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

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BLUE)Built library: $(NAME)$(RESET)"

bonus: all $(BONUS_DONE)

$(OBJ_BONUS_DIR)%.o: %.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_DONE): $(OBJ_BONUS)
	@ar rus $(NAME) $(OBJ_BONUS)
	@ranlib $(NAME)
	@echo "$(BLUE)Built library with bonuses: $(NAME)$(RESET)"
	@touch $(BONUS_DONE)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@echo "$(RED)Removed object files from libft!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)!$(RESET)"

re:fclean all

.PHONY: all clean fclean re bonus

