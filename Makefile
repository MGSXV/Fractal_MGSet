# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:33:08 by sel-kham          #+#    #+#              #
#    Updated: 2022/03/07 20:06:30 by sel-kham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS
CFLAGS := -Wall -Wextra -Werror
MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

# DIRECTORIES
INC_DIR := includes
SRC_DIR := src
OBJ_DIR := obj
HEAD_DIR := $(INC_DIR)/headers
LIBFT_DIR := $(INC_DIR)/libft
PRINTF_DIR := $(INC_DIR)/ft_printf
ROUTE := $(SRC_DIR)/route
HELPERS := $(SRC_DIR)/helpers
HANDLERS := $(SRC_DIR)/handlers

NAME := fractol

PRINTF := $(PRINTF_DIR)/libftprintf.a
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := $(HEAD_DIR)/fractol.h $(HEAD_DIR)/types.h
SRC := $(HELPERS)/ft_error_exit.c\
		$(HANDLERS)/handler.c\
		$(ROUTE)/router.c
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
MAIN := $(SRC_DIR)/main.c

################# COLORS #################
RED := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
SIGNATURE := $(WHITE)\n███████ ██████   █████   ██████ ████████  ██████  ██      \n██      ██   ██ ██   ██ ██         ██    ██    ██ ██      \n█████   ██████  ███████ ██         ██    ██    ██ ██      \n██      ██   ██ ██   ██ ██         ██    ██    ██ ██      \n██      ██   ██ ██   ██  ██████    ██     ██████  ███████ $(WHITE)BY\n$(RED)\n███╗   ███╗ ██████╗ ███████╗\n████╗ ████║██╔════╝ ██╔════╝\n██╔████╔██║██║  ███╗███████╗\n██║╚██╔╝██║██║   ██║╚════██║\n██║ ╚═╝ ██║╚██████╔╝███████║\n╚═╝     ╚═╝ ╚═════╝ ╚══════╝\n

.PHONY: all clean fclean re bonus

all: $(NAME)
	@echo "$(SIGNATURE)"

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(HEADERS) $(MAIN)
	@echo "$(GREEN)Making $(WHITE)fractol file..."
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MAIN) -o $(NAME)

$(OBJ_DIR)/%.o: $(HELPERS)/%.c
	@mkdir -p obj
	@$(CC) -c $< -o $@
$(OBJ_DIR)/%.o: $(HANDLERS)/%.c
	@mkdir -p obj
	@$(CC) -c $< -o $@
$(OBJ_DIR)/%.o: $(ROUTE)/%.c
	@mkdir -p obj
	@$(CC) -c $< -o $@

$(PRINTF): $(shell find $(PRINTF_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)ft_printf files..."
	@$(MAKE) -C $(PRINTF_DIR)/

$(LIBFT): $(shell find $(LIBFT_DIR) -name "*.c" -type f)
	@echo "$(GREEN)Making $(WHITE)libft files..."
	@$(MAKE) -C $(LIBFT_DIR)/

clean:
	@echo "$(RED)Removing $(WHITE)Fractol object files..."
	@rm -rf $(OBJ_DIR)/*.o
	@echo "$(RED)Removing $(WHITE)ft_printf object files..."
	@$(MAKE) -C $(PRINTF_DIR)/ clean
	@echo "$(RED)Removing $(WHITE)libft object files..."
	@$(MAKE) -C $(LIBFT_DIR)/ clean

fclean: clean
	@echo "$(RED)Removing $(WHITE)Fractol executable file..."
	@rm -rf $(NAME)
	@echo "$(RED)Removing $(WHITE)ft_printf static library file..."
	@$(MAKE) -C $(PRINTF_DIR)/ fclean
	@echo "$(RED)Removing $(WHITE)libft static library file..."
	@$(MAKE) -C $(LIBFT_DIR)/ fclean
	
re: fclean all