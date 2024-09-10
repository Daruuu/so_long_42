/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:32:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/10 02:07:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		exit_and_message(ERROR_FD);
	return (fd);
}

void	fill_player_and_coins(t_map *map, int x, int y, int *coins_flood)
{
	if (x < 0 || x > map->rows || y < 0 || y > map->columns)
		return ;
	if (*coins_flood == map->coins && map->matrix_map[x][y] == 'E')
	{
		map->matrix_map[x][y] = 'V';
	}
	if (map->matrix_map[x][y] == '1' || map->matrix_map[x][y] == 'V' \
		|| map->matrix_map[x][y] == 'E')
	{
		return ;
	}
	if (map->matrix_map[x][y] == 'C')
		(*coins_flood)++;
	map->matrix_map[x][y] = 'V';
	fill_player_and_coins(map, x + 1, y, coins_flood);
	fill_player_and_coins(map, x - 1, y, coins_flood);
	fill_player_and_coins(map, x, y + 1, coins_flood);
	fill_player_and_coins(map, x, y - 1, coins_flood);
}

static t_map	*fill_copy_matrix(t_map *map)
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

/*
 * TODO: erroe cuando encuentra todos los coins
 * y E es la ultima posicion en encontrar
 */

static void	aux_validations_flood_fill(t_map *map, t_map *map_copy, int *coins_flood)
{
	if (map->coins != *coins_flood)
	{
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
		return ;
	}
	if (check_map_items_coins_and_exit(map_copy) == 1)
	{
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
	}
	else
		free_map_copy(map_copy, ALL_VALIDATIONS_OK);
}

void	flood_fill(t_map *map, int x, int y)
{
	t_map	*map_copy;
	int		coins_flood;

	map_copy = fill_copy_matrix(map);
	if (map_copy == NULL)
	{
		free_struct_map_and_exit(ERROR_MEMORY_ALLOCATION, map);
		return ;
	}
	map_copy->rows = map->rows;
	map_copy->columns = map->columns;
	map_copy->coins = map->coins;
	coins_flood = 0;
	fill_player_and_coins(map_copy, x, y, &coins_flood);
	aux_validations_flood_fill(map, map_copy, &coins_flood);
}
