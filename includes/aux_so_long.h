/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_so_long.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:33:42 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/03 13:15:43 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_SO_LONG_h
# define AUX_SO_LONG_h 

//  GAME OBJECTS
# define PLAYER 'P'
# define EXIT_GAME 'E'
# define COLLECTIONABLE 'C'
# define WALL '1'
# define FLOOR '0'

# define ERROR_INVALID_MAP "Error INVALID MAP\n"
# define ERROR_ITEMS_IN_MAP "Error INVALID ITEMS IN MAP\n"
# define ERROR_IN_MATRIX "Error DATA IN MATRIX\n"
# define ERROR_MEMORY_ALLOCATION "Error DATA IN MATRIX\n"
# define ERROR_INVALID_EXTENSION_MAP "Error INVALID EXTENSION_MAP\n"
# define ERROR_COLUMNS_MAP "Error COLUMNS OF MAP\n"
# define ERROR_ROWS_MAP "Error ROWS OF MAP\n"
# define ERROR_LOADING_MAP "Error LOADING MAP\n"
# define ERROR_FD "Error FD < 0!\n"

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
// # define RESTART	114

# define WALL_XPM "assets/sprites/Tiles/blockSimple.xpm"
# define FLOOR_XPM "assets/sprites/Tiles/midBlocks_02.xpm"
# define COLLECT_XPM "assets/sprites/Collectibles/star_01.xpm"

# define PLAYER_FRONT_XPM "assets/sprites/Player/idle_00.xpm"
# define PLAYER_LEFT_XPM "assets/sprites/Player/walkLeft_00.xpm"
# define PLAYER_DOWN_XPM "assets/sprites/Player/walkDown_00.xpm"
# define PLAYER_RIGHT_XPM "assets/sprites/Player/walkRight_00.xpm"

# define EXIT_OPEN_XPM "assets/sprites/Exit/exit_open_01.xpm"
# define EXIT_CLOSED_XPM "assets/sprites/Exit/exit_close_01.xpm"

# define CELL_SIZE 32
# define TITLE_WINDOWS "So_long by Dasalaza"
# define WIN_GAME "You win the game!!\n"
# define CLOSE_GAME "Close game with Escape or Q!!\n"

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

// t_bool      map_alloc;// Bandera para verificar si el mapa ha sido alocado
/********Definición de t_bool si no está definida********/
// typedef struct  s_bool_true_false
// {
//     int false;
//     int true;
// }   t_bool;

# endif