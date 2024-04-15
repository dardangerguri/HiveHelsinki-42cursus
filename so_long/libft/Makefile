# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:08:35 by dgerguri          #+#    #+#              #
#    Updated: 2023/09/09 23:08:56 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror

INCLUDE = -I ./includes/

SRC_DIR = ./srcs/

SRC =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strncmp.c ft_strcmp.c ft_striteri.c ft_strdup.c ft_strchr.c ft_strrchr.c ft_strjoin.c ft_strtrim.c\
		ft_substr.c ft_strmapi.c ft_strnstr.c ft_split.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		ft_memcmp.c ft_bzero.c ft_calloc.c ft_memset.c ft_memchr.c ft_memcpy.c ft_memmove.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_atoi.c ft_itoa.c\
		ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c\
		ft_lstlast.c ft_lstnew.c ft_lstmap.c get_next_line.c\
		ft_printf/ft_printf.c ft_printf/hexadecimal_printf.c ft_printf/unsigned_decimal_printf.c\
		ft_print_array.c \

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BLUE)Built library: $(NAME)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files from libft!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)!$(RESET)"

re:fclean all

.PHONY: all clean fclean re

