/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:02:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/03 14:16:48 by  dasalaza        ###   ########.fr       */
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

// VALIDATIONS MAP
int     validate_filename_map(char **av);

#endif
