/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:35:49 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/12 00:40:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

//	COLORS IN ERRRORS
# define R_COLOR "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

//  GAME OBJECTS
# define PLAYER 'P'
# define EXIT_GAME 'E'
# define COLLECTIONABLE 'C'
# define WALL '1'
# define FLOOR '0'

# define LEFT_POSITION 0
# define RIGHT_POSITION 1
//# define UP_POSITION 2
//# define DOWN_POSITION 3
# define BACK_POSITION 2
# define FRONT_POSITION 3

# define ERROR_INVALID_MAP RED "Error: INVALID MAP\n" R_COLOR
# define ERROR_EMPTY_FILE YELLOW "Error: EMPTY FILE\n" R_COLOR
# define ERROR_ITEMS_IN_MAP MAGENTA "Error: INVALID ITEMS IN MAP\n" R_COLOR
# define ERROR_IN_MATRIX CYAN "Error: DATA IN MATRIX\n" R_COLOR
# define ERROR_MEMORY_ALLOCATION RED "Error: MEMORY ALLOCATION\n" R_COLOR
# define ERROR_INVALID_EXTENSION_MAP RED "Error: INVALID EXTENSION MAP\n" \
	R_COLOR
# define ERROR_COLUMNS_MAP RED "Error: COLUMNS OF MAP\n" R_COLOR
# define ERROR_ROWS_MAP RED "Error: ROWS OF MAP\n" R_COLOR
# define ERROR_LOADING_MAP YELLOW "Error: LOADING MAP\n" R_COLOR
# define ERROR_FD MAGENTA "Error: FD < 0!\n" R_COLOR
# define ERROR_MLX_PTR RED "Error: init mlx_ptr\n" R_COLOR
# define ERROR_WIN_PTR RED "Error: init win_ptr\n" R_COLOR

#define ALL_VALIDATIONS_OK GREEN "\
           _ _  __      __   _ _     _       _   _                         _    \n\
    /\\   | | | \\ \\    / /  | (_)   | |     | | (_)                       | |   \n\
   /  \\  | | |  \\ \\  / /_ _| |_  __| | __ _| |_ _  ___  _ __  ___    ___ | | __\n\
  / /\\ \\ | | |   \\ \\/ / _` | | |/ _` |/ _` | __| |/ _ \\| '_ \\/ __|  / _ \\| |/ /\n\
 / ____ \\| | |    \\  / (_| | | | (_| | (_| | |_| | (_) | | | \\__ \\ | (_) |   < \n\
/_/    \\_\\_|_|     \\/ \\__,_|_|_|\\__,_|\\__,_|\\__|_|\\___/|_| |_|___/  \\___/|_|\\_\\\n\
                                                                              \n" R_COLOR
#define QUIT_OF_GAME YELLOW "\
 ____        _ _            __                               \n\
/ __ \\      (_) |          / _|                              \n\
| |  | |_   _ _| |_    ___ | |_    __ _  __ _ _ __ ___   ___  \n\
| |  | | | | | | __|  / _ \\|  _|  / _` |/ _` | '_ ` _ \\ / _ \\ \n\
| |__| | |_| | | |_  | (_) | |   | (_| | (_| | | | | | |  __/ \n\
 \\___\\_\\\\__,_|_|\\__|  \\___/|_|    \\__, |\\__,_|_| |_| |_|\\___| \n\
                                   __/ |                     \n\
                                  |___/                      \n" R_COLOR

# define EXIT_GAME_MESSAGE YELLOW "\
 ______                        ____        _ _      _____                      \n\
|  ____|                      / __ \\      (_) |    / ____|                     \n\
| |__   _ __ _ __ ___  _ __  | |  | |_   _ _| |_  | |  __  __ _ _ __ ___   ___  \n\
|  __| | '__| '__/ _ \\| '__| | |  | | | | | | __| | | |_ |/ _` | '_ ` _ \\ / _ \\ \n\
| |____| |  | | | (_) | |    | |__| | |_| | | |_  | |__| | (_| | | | | | |  __/ \n\
|______|_|  |_|  \\___/|_|     \\___\\_\\\\__,_|_|\\__|  \\_____|\\__,_|_| |_| |_|\\___| \n\
                                                                               \n\
    __                                                                        \n\
 _ / /                                                                        \n\
(_) |                                                                         \n\
  | |                                                                         \n\
 _| |                                                                         \n\
(_) |                                                                         \n\
   \\_\\                                                                       \n" R_COLOR

/*
#define EXIT_GAME_MESSAGE "\
  __      __   _ _     _       _   _                    ____  _      __  \n\
  \\ \\    / /  | (_)   | |     | | (_)                  / __ \\| |     \\ \\ \n\
   \\ \\  / /_ _| |_  __| | __ _| |_ _  ___  _ __  ___  | |  | | | __ (_) |\n\
    \\ \\/ / _` | | |/ _` |/ _` | __| |/ _ \\| '_ \\/ __| | |  | | |/ /   | |\n\
     \\  / (_| | | | (_| | (_| | |_| | (_) | | | \\__ \\ | |__| |   <   _| |\n\
      \\/ \\__,_|_|_|\\__,_|\\__,_|\\__|_|\\___/|_| |_|___/  \\____/|_|\\_\\ (_) |\n\
                                                                       /_/ \n\
" R_COLOR
*/

//  GAME OBJECTS
# define ESC			65307
# define KEY_Q			113

# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100

# define LEFT		65361
# define UP			65362
# define RIGHT		65363
# define DOWN		65364

// Macros definidas en CMakeLists.txt para las rutas .xpm

/*
# define WALL_XPM TILES_DIR				"/blockSimple.xpm"
# define FLOOR_XPM TILES_DIR 			"/midBlocks_02.xpm"
# define COLLECT_XPM COLLECTIBLES_DIR	"/star_01.xpm"

# define PLAYER_FRONT_XPM PLAYER_DIR	"/idle_00.xpm"
# define PLAYER_LEFT_XPM PLAYER_DIR		"/walkLeft_00.xpm"
# define PLAYER_DOWN_XPM PLAYER_DIR		"/walkDown_00.xpm"
# define PLAYER_RIGHT_XPM PLAYER_DIR	"/walkRight_00.xpm"

# define EXIT_OPEN_XPM EXIT_DIR			"/exit_open_01.xpm"
# define EXIT_CLOSED_XPM EXIT_DIR		"/exit_close_01.xpm"
*/

// Macros defined in Makefile  to use paths of images .xpm

# define WALL_XPM "assets/sprites/Tiles/blockSimple.xpm"
# define FLOOR_XPM "assets/sprites/Tiles/midBlocks_02.xpm"
# define COLLECT_XPM "assets/sprites/Collectibles/star_01.xpm"

# define PLAYER_FRONT_XPM "assets/sprites/Player/idle_00.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/Player/walkLeft_00.xpm"
# define PLAYER_DOWN_XPM "assets/sprites/Player/walkDown_00.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/Player/walkRight_00.xpm"

# define EXIT_OPEN_XPM "assets/sprites/Exit/exit_open_01.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/Exit/exit_close_01.xpm"

# define CELL_SIZE			32
# define TITLE_WINDOWS		"So_long by Dasalaza"
# define WIN_GAME			"You win the game!!\n"
# define CLOSE_GAME			"Close game with Escape or Q!!\n"

/********Estructura para posiciones en 2D*****/

typedef struct s_position
{
	int	x; // Coordenada X
	int	y; // Coordenada Y
}	t_position;

/********Estructura para gestionar imágenes****/

typedef struct s_image
{
	void		*xpm_ptr;// Puntero a la imagen (por ejemplo, en formato XPM)
	t_position	win_pos;// Coordenadas en la ventana
}	t_image;

/******* Estructura para el mapa del juego******/

typedef struct s_map
{
	char		**matrix_map;// Mapa representado como una matriz de cadenas
	int			rows;// Número de filas en el mapa
	int			columns;// Número de columnas en el mapa
	int			coins;// Número de monedas en el mapa
	int			exits;// Número de salidas en el mapa
	int			players;// Número de jugadores en el mapa
	t_position	player_pos; // Posición del jugador
	t_position	exit_pos; // Posición del jugador
}	t_map;

/* *******Estructura principal del juego*** */
typedef struct s_game
{
	void		*mlx_ptr;// Puntero a la instancia de MiniLibX o similar
	void		*win_ptr;// Puntero a la ventana del juego
	int			count_moves;// Contador de movimientos
	int			player_sprite;// Identificador del sprite del jugador
	t_map		*map;// Información del mapa
	/*	Imágenes	*/
	t_image		wall;			// Imagen para las paredes
	t_image		floor;			// Imagen para el suelo
	t_image		coins;			// Imagen para las monedas
	t_image		exit_open;		// Imagen para la salida abierta
	t_image		exit_closed;	// Imagen para la salida cerrada
	/*	player images	*/
	t_image		player_front;	// Imagen del jugador mirando hacia adelante
	t_image		player_left;	// Imagen del jugador mirando hacia la izquierda
	t_image		player_right;	// Imagen del jugador mirando hacia la derecha
	t_image		player_back;	// Imagen del jugador mirando hacia atrás
}	t_game;

#endif