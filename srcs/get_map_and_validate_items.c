/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/13 16:38:49 by  dasalaza        ###   ########.fr       */
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
		exit_and_message("error memory allocation of MATRIX IN MAP STRUCT\n");
	i = 0;
	while (map->matrix_map[i] != NULL)
		i++;
	if (map->rows != i)
	{
		ft_printf("matrix ROWS no correct!!");
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
			ft_printf("matrix COLUMNS not correct!!");
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
		ft_printf("ERROR MINIM COINS OR MAX EXITS OR MAX PLAYERS\n");
		free_struct_map_and_exit(map);
	}
	else
		ft_printf("ITEMS IN MAP ARE CORRECT\n");
}

/* VALIDATE MAP WITH FLOOD FILL
INICIALIZACION:
	start: posicion de P
	marcar la posicion P[x][x] como visitado
EXPLORACION:
	explorar todos los vecinos de P posicion
	celdas:
		arriba
		abajo
		izquierda
		derecha
	mirar que sean caminos abierto '0'
REPETICION:
	repetir accion hasta encontrar la posicion E
DETERMINACION:
	si 'E' se encuentra, el algoritmo se detiene y puede reconstruir el camino de E a P
*/

// (map, map->player_pos->x, map->player_pos->y)
void fill(t_map *map, int x, int y, int *exit_reachable)
{
	if (x < 0 || x > map->rows || y < 0 || y > map->columns ||
		map->matrix_map[x][y] == WALL || map->matrix_map[x][y] == 'F')
		return ;
	if (map->matrix_map[x][y] == COLLECTIONABLE)
		map->coins --;
	if (map->matrix_map[x][y] == EXIT_GAME) {
		printf("x: %d, y: %d\n", x, y);
		*exit_reachable = *exit_reachable + 1;
	}
	map->matrix_map[x][y] = 'F';

//	print_map(map);

	fill(map, x + 1, y, exit_reachable);
	fill(map, x - 1, y, exit_reachable);
	fill(map, x, y + 1, exit_reachable);
	fill(map, x, y - 1, exit_reachable);
}

void	flood_fill(t_map *map, int x, int y)
{
	int exit_reachable;

	exit_reachable = 0; // not reachable
	fill(map, x, y, &exit_reachable);
	if (exit_reachable > 0) {
		// Se puede llegar de player a exit.
		printf("number of paths: %d\n", exit_reachable);
	}
	if (map->coins == 0)
	{
		ft_printf("VALID FLOOD FILL !!!\n");
	}
}