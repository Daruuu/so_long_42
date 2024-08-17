/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:58:03 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/17 20:41:48 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		exit_and_message("fd < 0");
	return (fd);
}

void	fill_player_and_coins(t_map *map, int x, int y)
{
	if (x < 0 || x > map->rows || y < 0 || y > map->columns || \
		map->matrix_map[x][y] == WALL || map->matrix_map[x][y] == 'F')
		return ;
	map->matrix_map[x][y] = 'F';
	fill_player_and_coins(map, x + 1, y);
	fill_player_and_coins(map, x - 1, y);
	fill_player_and_coins(map, x, y + 1);
	fill_player_and_coins(map, x, y - 1);
}

t_map	*fill_copy_matrix(t_map *map)
{
	t_map	*map_copy;
	int		i;

	map_copy = malloc(sizeof (t_map));
	if (!map_copy)
		return (NULL);
	map_copy->matrix_map = malloc(sizeof(char *) * map->rows);
	if (map_copy->matrix_map == NULL)
	{
		free(map_copy);
		return (NULL);
	}
	i = 0;
	while (i < map->rows)
	{
		map_copy->matrix_map[i] = ft_strdup(map->matrix_map[i]);
		if (map_copy->matrix_map[i] == NULL)
		{
			free_map_copy(map_copy, ERROR_MEMORY_ALLOCATION);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	flood_fill(t_map *map, int x, int y)
{
	t_map	*map_copy;

	map_copy = fill_copy_matrix(map);
	if (map_copy == NULL)
	{
		free(map_copy);
		free_struct_map_and_exit(ERROR_MEMORY_ALLOCATION, map);
		return ;
	}
	map_copy->rows = map->rows;
	map_copy->columns = map->columns;
	fill_player_and_coins(map_copy, x, y);
	if (check_map_items_coins_and_exit(map_copy) == 1)
	{
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
	}
	else
	{
		free_map_copy(map_copy, NULL);
		ft_printf("ALL VALIDATIONS IN MAP OKAY\n");
	}
}
