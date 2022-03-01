# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:33:08 by sel-kham          #+#    #+#              #
#    Updated: 2022/03/01 19:35:37 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror

NAME := fractol

PRINTF_DIR := ft_printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m

.PHONY: all clean fclean re bonus

all: $(NAME)
