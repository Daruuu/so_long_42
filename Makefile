ROOT_DIR := $(shell pwd)

ASSETS_DIR := $(ROOT_DIR)/assets/sprites

TILES_DIR := $(ASSETS_DIR)/Tiles
COLLECTIBLES_DIR := $(ASSETS_DIR)/Collectibles
PLAYER_DIR := $(ASSETS_DIR)/Player
EXIT_DIR := $(ASSETS_DIR)/Exit

NAME = so_long
CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes \
			-I$(MLX_DIR)/include -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -g
			-DTILES_DIR=\"$(TILES_DIR)\" \
			-DCOLLECTIBLES_DIR=\"$(COLLECTIBLES_DIR)\" \
			-DPLAYER_DIR=\"$(PLAYER_DIR)\" \
			-DEXIT_DIR=\$(EXIT_DIR)

SRC_DIR = srcs
OBJ_DIR = objs

#------------------------libs--------------------------------

LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
GNL_DIR = libs/get_next_line
MLX_DIR = libs/minilibx-linux
NO_PRINT_DIRS = --no-print-directory

# CODAM MLX
#MLX_DIR = libs/MLX42

SO_LONG_H = includes/so_long.h

#------------------------ FONT FILES & OBJECTS --------------------------------

# SRC = $(wildcard $(SRC_DIR)/*.c) main.c
#		$(SRC_DIR)/*.c
SRC =	$(SRC_DIR)/so_long.c \
		$(SRC_DIR)/validations_map.c \
		$(SRC_DIR)/ft_free_errors.c \
		$(SRC_DIR)/init_structs.c \
		$(SRC_DIR)/get_map_and_validate_items.c \
		$(SRC_DIR)/graphics.c \
		$(SRC_DIR)/print_functions.c \
		$(SRC_DIR)/flood_fill.c \
		$(SRC_DIR)/moves_game.c \

OBJ =	$(SRC:%.c=$(OBJ_DIR)/%.o)

#-------------------------------- LIBS --------------------------------

LIB_LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF = $(PRINTF_DIR)/printf.a
LIB_GNL = $(GNL_DIR)/get_next_line.a
LIB_MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
#LIB_MLX = -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm		// codam mlx

ALL_LIBS = $(LIB_LIBFT) $(LIB_PRINTF) $(LIB_GNL)

# ========================= RULES SO_LONG =================================

#all: $(ALL_LIBS) $(MLX_DIR)/build/libmlx42.a $(NAME)
all: $(ALL_LIBS) $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) $(ALL_LIBS) $(LIB_MLX) -o $(NAME)

# ---------------------------- COMPILE OF LIBS -------------------------------

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR) $(NO_PRINT_DIRS)

$(PRINTF_DIR)/printf.a:
	@$(MAKE) -C $(PRINTF_DIR) $(NO_PRINT_DIRS)

$(GNL_DIR)/get_next_line.a:
	@$(MAKE) -C $(GNL_DIR) $(NO_PRINT_DIRS)

#$(MLX_DIR)/build/libmlx42.a:
#	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
#	@cmake --build $(MLX_DIR)/build
$(MLX_DIR)/libmlx_Linux.a:
	@$(MAKE) -C $(MLX_DIR) $(NO_PRINT_DIRS)

# ---------------------------- COMPILE OBJECTS  -------------------------------

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SO_LONG_H)
$(OBJ_DIR)/%.o: %.c $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -rf $(OBJ_DIR)
#	rm -rf $(OBJ_DIR)/*.o
#	rm -rf $(MLX_DIR)/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	#$(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
