/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:02:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/07 18:25:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/minilibx-linux/mlx.h"
#include "../libs/libft/libft.h"
#include "../libs/printf/ft_printf.h"
#include "../libs/get_next_line/get_next_line.h"
#include "custom_macros.h"

#include <fcntl.h>	// read
#include <string.h>	// strerror
#include <stdlib.h>

// VALIDATIONS MAP
// int     validate_filename_map(char **av);
void        all_validations(char **av);

// ********** FT_FREE_ERRORS.C ***********************

void        if_not_exist_free_pointer(char **ptr);

// ********** FT_AUX.C ***********************
void        *ft_realloc(void *ptr, size_t new_size);

#endif
