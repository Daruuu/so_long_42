NAME = so_long
CC = CC
CFLAGS = -Wall -Wextra -Werror -I includes -I$(MLX_DIR) -I$(LIBFT_DIR)

SRC_DIR = srcs/
OBJ_DIR = objs/

#------------------------libs--------------------------------

MLX_DIR = minilibx_linux
LIBFT_DIR = libs/libft
PRINTF_DIR = libs/printf
GNL_DIR = libft/gnl
SO_LONG_H = include/so_long.h

#------------------------ FONT FILES & OBJECTS --------------------------------

SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/game.c $(SRC_DIR)/map.c $(SRC_DIR)/graphics.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#-------------------------------- LIBS --------------------------------

LIB_LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF = $()
LIB_GNL = $()
LIB_MLX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lx11 -lm -lz

# ========================= RULES SO_LONG =================================

all: $(LIBFT_DIR) $(MLX_DIR)/libmlx_Linux.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_DIR) $(LIB_PRINTF) $(LIB_GNL) $(LIB_MLX) -o $(NAME)

# ---------------------------- COMPILE OF LIBS -------------------------------

$(C_LIBFT):
		$(MAKE) -C $(LIB_LIBFT)

$(C_)

