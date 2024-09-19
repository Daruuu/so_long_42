/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:57:46 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/19 12:57:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_player_and_coins(t_map *map, int x, int y, int *coins_flood)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
	if (map->matrix_map[x][y] == '1' || map->matrix_map[x][y] == 'V' \
		|| map->matrix_map[x][y] == 'E')
	{
		return ;
	}
	if (map->matrix_map[x][y] == 'C')
		(*coins_flood)++;
	map->matrix_map[x][y] = 'V';
	flood_player_and_coins(map, x + 1, y, coins_flood);
	flood_player_and_coins(map, x - 1, y, coins_flood);
	flood_player_and_coins(map, x, y + 1, coins_flood);
	flood_player_and_coins(map, x, y - 1, coins_flood);
}

static void	flood_fill_exit(t_map *map, int x, int y, int *coins_flood_exit)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
	if (map->matrix_map[x][y] == '1' || map->matrix_map[x][y] == 'V')
	{
		return ;
	}
	if (map->matrix_map[x][y] == 'C')
		(*coins_flood_exit)++;
	map->matrix_map[x][y] = 'V';
	flood_fill_exit(map, x + 1, y, coins_flood_exit);
	flood_fill_exit(map, x - 1, y, coins_flood_exit);
	flood_fill_exit(map, x, y + 1, coins_flood_exit);
	flood_fill_exit(map, x, y - 1, coins_flood_exit);
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

int	prepare_flood_fill(t_map *map, t_map **map_copy, t_map **map_copy_exit)
{
	*map_copy = fill_copy_matrix(map);
	*map_copy_exit = fill_copy_matrix(map);
	if (*map_copy == NULL || *map_copy_exit == NULL)
	{
		free_map_copy(*map_copy, NULL);
		free_map_copy(*map_copy_exit, NULL);
		return (1);
	}
	(*map_copy)->rows = map->rows;
	(*map_copy)->columns = map->columns;
	(*map_copy)->coins = map->coins;
	(*map_copy_exit)->rows = map->rows;
	(*map_copy_exit)->columns = map->columns;
	return (0);
}

int	flood_fill(t_map *map, int x, int y)
{
	t_map	*map_copy;
	t_map	*map_copy_exit;
	int		coins_flood;
	int		coins_exit;

	coins_flood = 0;
	coins_exit = 0;
	if (prepare_flood_fill(map, &map_copy, &map_copy_exit) == 1)
		return (1);
	flood_player_and_coins(map_copy, x, y, &coins_flood);
	flood_fill_exit(map_copy_exit, x, y, &coins_exit);
	if (map->coins == coins_flood && map->coins == coins_exit && \
		map_copy_exit->matrix_map[map->exit_pos.x][map->exit_pos.y] == 'V')
	{
		free_map_copy(map_copy, NULL);
		free_map_copy(map_copy_exit, ALL_VALIDATIONS_OK);
		return (0);
	}
	else
	{
		free_map_copy(map_copy, NULL);
		free_map_copy(map_copy_exit, NULL);
		return (1);
	}
}
