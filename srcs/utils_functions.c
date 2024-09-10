/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:33 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/10 17:28:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	aux_flood_check_map_items(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (map->matrix_map[x][y] == 'E')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	aux_check_all_ones(const char *line, t_map *map)
{
	int	j;

	j = 0;
	while (j < map->columns)
	{
		if (line[j] != WALL)
			return (1);
		j++;
	}
	return (0);
}

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		exit_and_message(ERROR_FD);
	return (fd);
}
