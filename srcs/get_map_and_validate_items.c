/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:44:02 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/07 14:55:53 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	check_buffer_items_map(char *buffer_map)
// {
// 	int	i;

// 	i = 0;
// 	while (buffer_map[i] != '\0')
// 	{
// 		// Verificamos si el carácter es uno de los permitidos
// 		if (buffer_map[i] != '1' && // Pared
// 			buffer_map[i] != 'P' && // Jugador
// 			buffer_map[i] != 'E' && // Salida
// 			buffer_map[i] != 'C' && // Coleccionable
// 			buffer_map[i] != '0' && // Piso
// 			buffer_map[i] != '\n')  // Saltos de línea
// 		{
// 			ft_printf("Error: ítem inválido en el BUFFER, carácter: '%c' en la posición %d\n", buffer_map[i], i);
// 			free(buffer_map);
// 			exit(2); // Salida con código de error
// 		}
// 		i++;
// 	}
// }

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
		exit_and_message(ERROR_INVALID_MAP);
	new_map = (char *) malloc(i + 1);
	if (!new_map)
		free_ptr(ERROR_MEMORY_ALLOCATION, new_map);
	fd = open(path, O_RDONLY);
	read (fd, new_map, i);
	new_map[i] = '\0';
	close(fd);
	ft_printf("MAPA:\n%s\n", new_map);
	// check_buffer_items_map(new_map);
	return (new_map);
}

void	add_map_to_matrix(char *map_ptr, t_map *map)
{
	int	i;
	int	j;

	map->matrix_map = ft_split(map_ptr, '\n');
	free(map_ptr);
	if (!map->matrix_map)
	{
		free_map_copy(map, NULL);
		exit_and_message(ERROR_MEMORY_ALLOCATION);
	}
	i = 0;
	while (map->matrix_map[i] != NULL)
		i++;
	if (map->rows != i)
		free_struct_map_and_exit(ERROR_IN_MATRIX, map);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->matrix_map[i][j] != '\0')
			j++;
		if (j != map->columns)
			free_struct_map_and_exit(ERROR_IN_MATRIX, map);
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

// change name
// check_map_after_flood_fill();
int	check_map_items_coins_and_exit(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	ft_printf("CHECK_MAP_ITEMS_COINS_AND_EXIT()\n");
	ft_printf("ROWS: %d\n", map->rows);
	ft_printf("COLS: %d\n", map->columns);
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (map->matrix_map[x][y] == '0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

/*
static void	aux_check_player_exit_coins(t_map *map, int i, int j)
{
	if (map->matrix_map[i][j] == PLAYER)
	{
		map->players++;
	}
	else if (map->matrix_map[i][j] == COLLECTIONABLE)
	{
		map->coins++;
	}
	else if (map->matrix_map[i][j] == EXIT_GAME)
	{
		map->exits++;
	}
}

void	check_minim_items_in_map(t_map *map)
{
	int	i;
	int	j;

	i = 0; // Recorrer todo el mapa desde la primera fila
	while (i < map->rows)
	{
		j = 0; // Recorrer todo el mapa desde la primera columna
		while (j < map->columns)
		{
			aux_check_player_exit_coins(map, i, j);
			j++;
		}
		i++;
	}

	// Verificar si el mapa tiene exactamente 1 jugador, 1 salida y al menos 1 moneda
	if (map->players != 1 || map->exits != 1 || map->coins < 1)
	{
		free_struct_map_and_exit(ERROR_ITEMS_IN_MAP, map);
	}
	get_positions_player_and_exit(map);
}

*/

static void	aux_check_player_exit_coins(t_map *map, int i, int j)
{
	if (map->matrix_map[i][j] == PLAYER)
	{
		map->players ++;
		if (map->players != 1)
		free_struct_map_and_exit(ERROR_ITEMS_IN_MAP, map);
	}
	else if (map->matrix_map[i][j] == COLLECTIONABLE)
	{
		map->coins++;
		if (map->coins < 1)
			free_struct_map_and_exit(ERROR_ITEMS_IN_MAP, map);
	}
	else if (map->matrix_map[i][j] == EXIT_GAME)
	{
		map->exits++;
		if (map->exits != 1)
			free_struct_map_and_exit(ERROR_ITEMS_IN_MAP, map);
	}
}

void	check_minim_items_in_map(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	ft_printf("minim itemmsmsmmsmsm\n");
	while (i < map->rows)
	{
		j = 1;
		while (j < map->columns)
		{
			aux_check_player_exit_coins(map, i, j);
			j++;
		}
		i++;
	}
	get_positions_player_and_exit(map);
}
