# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 19:33:08 by sel-kham          #+#    #+#              #
#    Updated: 2022/03/15 23:31:31 by sel-kham         ###   ########.fr        #
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
FREACTALS := $(SRC_DIR)/fractals
INIT := $(SRC_DIR)/init

NAME := fractol

PRINTF := $(PRINTF_DIR)/libftprintf.a
LIBFT := $(LIBFT_DIR)/libft.a
HEADERS := $(HEAD_DIR)/fractol.h $(HEAD_DIR)/types.h $(HEAD_DIR)/macos_keys.h
SRC := $(HELPERS)/ft_error_exit.c $(HELPERS)/mg_pixel_put.c $(HELPERS)/ft_complex_numbers.c $(HELPERS)/ft_color.c\
		$(HANDLERS)/keyboard_events.c $(HANDLERS)/mouse_events.c\
		$(ROUTE)/router.c\
		$(INIT)/window_init.c\
		$(FREACTALS)/ft_madelbrot_set.c

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
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(HANDLERS)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(ROUTE)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(INIT)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(FREACTALS)/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

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