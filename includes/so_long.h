/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:32:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/10 16:06:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "so_long_utils.h"
# include <fcntl.h>// read
# include <stdlib.h>
//# include "../libs/minilibx-linux/mlx.h"
//# include "../libs/MLX42/include/MLX42/MLX42.h"

/* *************VALIDATIONS MAP **********/

void		validate_file_and_edge_of_map(char *av1, t_map **map);

// ********** FT_FREE_ERRORS.C ***********************

void		exit_and_message(char *message);
void		free_ptr(char *message, char *ptr);
void		free_map_copy(t_map *map_copy, char *message);
void		free_struct_map_and_exit(char *message, t_map *map);

// ********** FT_FREE_GAME.C ***********************

void		free_game_complete(t_game *game);
void		free_images_xpm(t_game *game);
void		free_game_ptr(t_game *game, char *message);
void		free_struct_game(t_game *game, char *message);

// ********** PRINT_FUNCTIONS.C ***********************

void		print_map(t_map *map);
void		print_map_data(t_map *map);
void		print_game_data(t_game *game);
void		free_and_close(char *line, int fd);
void		free_exit_file_columns_map(char *line, char *message);

// ********** GET_MAP_AND_VALIDATE_ITEMS.C ***********************

char		*get_map_from_file(char *path);
void		add_map_to_matrix(char *map_ptr, t_map *map);
void		check_minim_items_in_map(t_map *map);

// ********** FLOOD_FILL.C ***********************

int			can_open_fd(char *path_map);
int flood_fill(t_map *map, int x, int y);

// ********** INIT_STRUCTS.C ***********************

t_map		*init_map(void);
t_game		*init_game(void);
void		init_game_windows_data(t_game *game);
void		check_image_texture(t_game *game, void **image, char *path);

// ********** GRAPHICS.C ***********************

void		draw_map_sprites(t_game *game, int i, int j);
int			close_window(t_game *game);
void		load_textures_game(t_game *game);

// ********** MOVES_GAME.C ***********************

int			handle_event_keyboard(int keysym, t_game *game);
void		update_floor_or_coins(t_game *game, int new_x, int new_y);

// ********** UTILS_FUNCTIONS.C ***********************
int			aux_check_all_ones(const char *line, t_map *map);
int			aux_flood_check_map_items(t_map *map);

#endif
