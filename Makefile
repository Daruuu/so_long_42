NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

SRC_DIR = srcs
OBJ_DIR = objs

#------------------------libs--------------------------------

LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
GNL_DIR = libs/get_next_line
MLX_DIR = libs/minilibx-linux

SO_LONG_H = include/so_long.h

#------------------------ FONT FILES & OBJECTS --------------------------------

# SRC = $(wildcard $(SRC_DIR)/*.c) main.c
SRC =	main.c	\
		$(SRC_DIR)/validations_map.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/graphics.c \
		$(SRC_DIR)/so_long.c \
		$(SRC_DIR)/get_map_with_gnl.c \

OBJ =	$(SRC:%.c=$(OBJ_DIR)/%.o)
#OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#OBJ := $(OBJ:main.c=$(OBJ_DIR)/main.o)

#-------------------------------- LIBS --------------------------------

LIB_LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF = $(PRINTF_DIR)/printf.a
LIB_GNL = $(GNL_DIR)/get_next_line.a
LIB_MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

ALL_LIBS = $(LIB_LIBFT) $(LIB_PRINTF) $(LIB_GNL)

# ========================= RULES SO_LONG =================================

all: $(ALL_LIBS) $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(ALL_LIBS) $(LIB_MLX) -o $(NAME)

# ---------------------------- COMPILE OF LIBS -------------------------------

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_DIR)/printf.a:
	$(MAKE) -C $(PRINTF_DIR)

$(GNL_DIR)/get_next_line.a:
	$(MAKE) -C $(GNL_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)

# ---------------------------- COMPILE OBJECTS  -------------------------------

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SO_LONG_H)
$(OBJ_DIR)/%.o: %.c $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c $(SO_LONG_H)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
