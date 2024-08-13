/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:12:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/13 16:30:16 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "aux_so_long.h"
# include <fcntl.h>// read
# include <string.h>// strerror
# include <stdlib.h>

/* *************VALIDATIONS MAP **********/
void        validate_file_and_edge_of_map(char *av1);
int         can_open_fd(char *path_map);

// ********** FT_FREE_ERRORS.C ***********************
void		if_not_exist_free_pointer(char **ptr);
void		exit_and_message(char *message);
void        free_struct_map_and_exit(t_map *map);
void        free_ptr(char *message, char *ptr);

// ********** GET_MAP_AND_VALIDATE_ITEMS.C ***********************
char 		*get_map_from_file(char *path);
void        check_minim_items_in_map(t_map *map);
void        add_map_to_matrix(char *map_ptr, t_map *map);
void        flood_fill(t_map *map, int x, int y);

// ********** FT_AUX.C ***********************
void		*ft_realloc(void *ptr, size_t new_size);

// ********** INIT_STRUCTS.C ***********************

t_position	init__positions(void);
t_image		init_window(void);
t_map		*init_map(void);
t_game		init_game(void);

#endif