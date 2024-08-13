/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/13 14:46:47 by  dasalaza        ###   ########.fr       */
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
				map->player_pos.x = i;
				map->player_pos.y = j;
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
	if (map->players > 1 || map->exits > 1 || map->coins == 0)
	{
		ft_printf("ERROR MINIM COINS OR MAX EXITS OR MAX PLAYERS\n");
		free_struct_map_and_exit(map);
	}
	else
		ft_printf("MINIM ITEMS IN MAP ARE CORRECT\n");
	//	reset de items 
	get_positions_player_and_exit(map);	
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

void	check_map_player_to_exit(t_map *map, int x, int y, char to_fill) 
{

	
	while ((map->rows - 1) > 0)
	{
		while ((map->columns - 1) > 0)
		{
			if (map->matrix_map[map->player_pos.x][map->player_pos.y])

			map->columns --;
		}
		map->rows --;
	}

}