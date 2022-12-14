# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:01:59 by dgerguri          #+#    #+#              #
#    Updated: 2022/12/11 20:51:23 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

RM = rm -f

INCLUDE = ft_printf.h

LIBFT_D = ./libft
LIBFT = ./libft/libft.a

SRC = ft_printf.c unsigned_decimal_printf.c hexadecimal_printf.c

OBJ = ft_printf.o unsigned_decimal_printf.o hexadecimal_printf.o

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT_D)
	cp $(LIBFT) ./$(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	$(MAKE) clean -C $(LIBFT_D)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_D)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
