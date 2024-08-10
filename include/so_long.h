/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:20:51 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/11 00:04:53 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:02:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/09 14:16:54 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/minilibx-linux/mlx.h"
#include "../libs/libft/libft.h"
#include "../libs/printf/ft_printf.h"
#include "../libs/get_next_line/get_next_line.h"
#include "aux_so_long.h"

#include <fcntl.h>	// read
#include <string.h>	// strerror
#include <stdlib.h>

// VALIDATIONS MAP
// int     validate_filename_map(char **av);
void        aux_validations(char **av);

// ********** FT_FREE_ERRORS.C ***********************

void        if_not_exist_free_pointer(char **ptr);

// ********** FT_AUX.C ***********************
void        *ft_realloc(void *ptr, size_t new_size);

// ********** INIT_STRUCTS.C ***********************

t_position  init__positions(void);
t_image     init_window(void);
t_map       *init_map(void);
t_game      inti_game(void);

#endif
