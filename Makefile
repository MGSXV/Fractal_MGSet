# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:33:08 by sel-kham          #+#    #+#              #
#    Updated: 2022/03/01 21:18:55 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror

NAME := fractol
SRC := fractol.c

PRINTF_DIR := ft_printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m

.PHONY: all clean fclean re bonus

all: $(NAME)
	@echo "$(GREEN)Making $(WHITE)fractol file..."
	$(CC) $(FLAGS) $(SRC) $(PRINTF) -o $(NAME)


$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)Fractol object files..."
	@rm -rf *.o
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)Fractol executable file..."
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean