/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:44:02 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/07 15:05:52 by  dasalaza        ###   ########.fr       */
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
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
	if (map->matrix_map[x][y] == '1' || map->matrix_map[x][y] == 'X' \
		|| map->matrix_map[x][y] == 'E')
	{
		return ;
	}
	if (map->matrix_map[x][y] == 'C')
		(*coins_flood)++;
	map->matrix_map[x][y] = 'X';
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
static int	iterate_map_items(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	while (x < map->rows)
	{
		y = 1;
		while (y < map->columns)
		{
			// if (map->matrix_map[x][y] == '0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
*/

void	flood_fill(t_map *map, int x, int y)
{
	t_map	*map_copy;
	int		coins_flood;

	map_copy = fill_copy_matrix(map);
	if (map_copy == NULL)
		free_struct_map_and_exit(ERROR_MEMORY_ALLOCATION, map);
	// ft_printf("alksdjfklasdfjjkljsdlkfkasjld map_rows: %d\n", map->rows);
	// ft_printf("map_columns: %d\n", map->columns);
	map_copy->rows = map->rows;
	map_copy->columns = map->columns;
	// print_map_data(map);
	coins_flood = 0;

	ft_printf("map BEFORE de flood_fill()");
	print_map(map_copy);

	fill_player_and_coins(map_copy, x, y, &coins_flood);

	ft_printf("map AFTER de flood_fill()");
	print_map(map_copy);
	ft_printf("\n--------------------------------\n");




	ft_printf("coins map: %d\n", map->coins);
	ft_printf("coins_flood copy_map: %d\n", coins_flood);
	if (map->coins != coins_flood )
	{
		ft_printf("Error coins no valids!\n");
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
		// exit(2);
	}
	// print_map(map_copy);
	if (check_map_items_coins_and_exit(map_copy) == 1)
	{
		ft_printf("ENTRA en flood_filll()\n");
		free_map_copy(map_copy, ERROR_INVALID_MAP);
		free_struct_map_and_exit(NULL, map);
	}
	else
		free_map_copy(map_copy, ALL_VALIDATIONS_OK);
}
