# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:33:08 by sel-kham          #+#    #+#              #
#    Updated: 2022/03/02 18:12:02 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

NAME := fractol
HEADER := fractol.h

PRINTF_DIR := ft_printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

#HANDLERS_DIR := handlers
#HANDLERS := $(HANDLERS_DIR)/libftprintf.a
HELPERS_DIR := helpers
HELPERS := $(HELPERS_DIR)/ft_error.c
OBJ_DIR := objects

SRC := fractol.c $(HELPERS)
OBJ := $(SRC:.c=.o)


################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(HEADER)
	@ # @echo "$(GREEN)Making $(WHITE)fractol file..."
	$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR)/,$(notdir $(OBJ))) $(PRINTF) -o $(NAME)

%.o: %.c
	cc $< -c -o $(OBJ_DIR)/$(notdir $@)

$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)Fractol object files..."
	@rm -rf $(OBJ_DIR)/*.o
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)Fractol executable file..."
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean