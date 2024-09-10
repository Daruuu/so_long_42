/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:32:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/10 20:38:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_player_and_coins(t_map *map, int x, int y, int *coins_flood)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
//	if (*coins_flood == map->coins && map->matrix_map[x][y] == 'E')
//	{
//		map->matrix_map[x][y] = 'V';
//		return ;
//	}
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

static void flood_fill_exit(t_map *map, int x, int y, int *coins_flood_exit)
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


void	flood_fill(t_map *map, int x, int y)
{
	t_map	*map_copy;
	t_map	*map_copy_exit;
	int		coins_flood;
	int		coins_exit;

	map_copy = fill_copy_matrix(map);
	map_copy_exit = fill_copy_matrix(map);
	if (map_copy == NULL || map_copy_exit == NULL)
	{
		free_struct_map_and_exit(ERROR_MEMORY_ALLOCATION, map);
		return ;
	}
	map_copy->rows = map->rows;
	map_copy->columns = map->columns;
	map_copy->coins = map->coins;

	map_copy_exit->rows = map->rows;
	map_copy_exit->columns = map->columns;

	coins_flood = 0;
	coins_exit = 0;

	flood_player_and_coins(map_copy, x, y, &coins_flood);

	ft_printf("coins_flood: %d\n", coins_flood);
//	print_map(map_copy);

//	flood_fill_exit(map_copy_exit, x, y, &coins_exit);
//	flood_fill_exit(map_copy_exit, map->player_pos.x, map->player_pos.y, &coins_exit);

//	ft_printf("coins_flood_exit: %d\n", coins_flood);
//	print_map(map_copy_exit);

	if (map->coins == coins_flood && map->coins == coins_exit && \
		map_copy_exit->matrix_map[map->exit_pos.x][map->exit_pos.y] == 'V')
	{
		ft_printf("VALIDATIONS OKAYYYYYYYYY\n");
	}
	else
	{
		ft_printf("VALIDATIONS FAILEDDDDDDD\n");
		free_map_copy(map_copy, ALL_VALIDATIONS_OK);
		exit(2);
	}
//	aux_flood_fill(map, map_copy, &coins_flood, map_copy_exit);
}
/*
 * TODO: erroe cuando encuentra todos los coins
 * y E es la ultima posicion en encontrar
 */

/*
void	aux_flood_fill(t_map *map, t_map *map_copy, int *coins_flood, t_map *map_copy_exit)
{
	if (map->coins == *coins_flood && \
		map_copy_exit->matrix_map[map->exit_pos.x][map->exit_pos.y] == 'X')
	{
		ft_printf(ALL_VALIDATIONS_OK);
//		free_map_copy(map_copy, ERROR_INVALID_MAP);
//		free_struct_map_and_exit(NULL, map);
//		return ;
	}
	if (aux_flood_check_map_items(map_copy) == 1)
	{
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
	}
	else
		free_map_copy(map_copy, ALL_VALIDATIONS_OK);
}
*/
