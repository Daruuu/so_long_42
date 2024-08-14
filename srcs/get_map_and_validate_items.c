/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/14 18:29:05by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_map_from_file(char *path)
{
	char	*new_map;
	int		fd;
	char	buffer;
	int		i;

	fd = can_open_fd(path);
	i = 0;
	while (read(fd, &buffer, 1))
		i ++;
	close(fd);
	if (i == 0)
		exit_and_message("empty file\n");
	new_map = (char *) malloc(i + 1);
	if (!new_map)
		free_ptr("error allocation malloc()\n", new_map);
	fd = open(path, O_RDONLY);
	read (fd, new_map, i);
	new_map[i] = '\0';
	close(fd);
	return (new_map);
}

void	add_map_to_matrix(char *map_ptr, t_map *map)
{
	int	i;
	int	j;

	map->matrix_map = ft_split(map_ptr, '\n');
	free(map_ptr);
	if (!map->matrix_map)
		exit_and_message("error memory allocation of matrix in map struct\n");
	i = 0;
	while (map->matrix_map[i] != NULL)
		i++;
	if (map->rows != i)
	{
		ft_printf("matrix rows no correct!!");
		free_struct_map_and_exit(map);
	}
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->matrix_map[i][j] != '\0')
			j++;
		if (j != map->columns)
		{
			ft_printf("matrix columns not correct!!");
			free_struct_map_and_exit(map);
		}
		i++;
	}
}

static void	get_positions_player_and_exit(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->columns)
		{
			if (map->matrix_map[i][j] == PLAYER)
			{
				map->player_pos.x = i;
				map->player_pos.y = j;
			}
			if (map->matrix_map[i][j] == EXIT_GAME)
			{
				map->exit_pos.x = i;
				map->exit_pos.y = j;
			}
			j++;
		}
		i++;
	}
}

static int	check_map_item_coins_and_exit(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (map->matrix_map[x][y] == EXIT_GAME ||
				map->matrix_map[x][y] == COLLECTIONABLE)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

void	check_minim_items_in_map(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->columns)
		{
			if (map->matrix_map[i][j] == PLAYER)
				map->players ++;
			else if (map->matrix_map[i][j] == COLLECTIONABLE)
				map->coins++;
			else if (map->matrix_map[i][j] == EXIT_GAME)
				map->exits++;
			j++;
		}
		i++;
	}
	get_positions_player_and_exit(map);
	if (map->players > 1 || map->exits > 1 || map->coins == 0)
	{
		ft_printf("error minim coins or max exits or max players\n");
		free_struct_map_and_exit(map);
	}
	else
		ft_printf("items in map are correct\n");
}

/* validate map with flood fill_player_to_exit
inicializacion:
	start: posicion de p
	marcar la posicion p[x][x] como visitado
exploracion:
	explorar todos los vecinos de p posicion
	celdas:
		arriba
		abajo
		izquierda
		derecha
	mirar que sean caminos abierto '0'
repeticion:
	repetir accion hasta encontrar la posicion e
determinacion:
	si 'e' se encuentra, el algoritmo se detiene y puede reconstruir el camino de e a p
(map, map->player_pos->x, map->player_pos->y)
*/

void	fill_player_and_coins(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns ||
		map->matrix_map[x][y] == WALL || map->matrix_map[x][y] == 'f')
		return ;
	map->matrix_map[x][y] = 'f';
	print_map(map);
	fill_player_and_coins(map, x + 1, y);
	fill_player_and_coins(map, x - 1, y);
	fill_player_and_coins(map, x, y + 1);
	fill_player_and_coins(map, x, y - 1);
}

void	flood_fill(t_map *map, int x, int y)
{
	t_map	map_copy;
	int		i;

	map_copy.matrix_map = malloc(sizeof(char *) * map->rows);
	if (map_copy.matrix_map == NULL)
		return ;
	i = 0;
	while (i < map->rows)
	{
		map_copy.matrix_map[i] = ft_strdup(map->matrix_map[i]);
		i++;
	}

	fill_player_and_coins(&map_copy, x, y);

	if (check_map_item_coins_and_exit(&map_copy) == 0)
		ft_printf("ALL VALIDATIONS OKAY\n");
	else
		ft_printf("INVALID MAPP \n");
}

/*
void	flood_fill(t_map *map, int x, int y)
{
	t_map	map_case_exit;
	t_map	map_case_coins;
	int		i;

	i = 0;
	map_case_exit.matrix_map = malloc(sizeof(char *) * map->rows);
	map_case_coins.matrix_map = malloc(sizeof(char *) * map->columns);

	while (i < map->rows)
	{
		map_case_exit.matrix_map[i] = ft_strdup(map->matrix_map[i]);
		map_case_exit.matrix_map[i] = ft_strdup(map->matrix_map[i]);
		i++;
	}
	map_case_exit.rows = map->rows;
	map_case_exit.columns = map->columns;

	map_case_coins.rows = map->rows;
	map_case_coins.columns = map->columns;

	int	exit_reachable;
	int	coins_reachable;

	exit_reachable = 0;
	fill_player_to_exit(&map_case_exit, x, y, &exit_reachable);

	if (exit_reachable > 0)
	{
		// Se puede llegar de player a exit.
		ft_printf("number of paths to exits: %d\n", exit_reachable);
	}

	coins_reachable = 0;
	fill_player_search_coins(&map_case_coins, x, y, &coins_reachable);

	if (map->coins == coins_reachable)
	{
		ft_printf("VALID FLOOD fill_player_to_exit !!!\n");
	}
	while (i < map->rows)
	{
		free(map_case_exit.matrix_map[i]);
		free(map_case_coins.matrix_map[i]);
		i ++;
	}
	free(map_case_exit.matrix_map);
	free(map_case_coins.matrix_map);
}
*/