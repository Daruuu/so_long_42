/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:32:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/20 17:34:17 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map_from_file(char *path, t_game *game)
{
	char	*new_map;
	int		fd;
	char	buffer;
	int		i;

	fd = can_open_fd(path, game);
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
	return (new_map);
}

void	add_map_to_matrix(char *map_ptr, t_map *map, t_game *game)
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
		free_struct_map_and_exit(ERROR_IN_MATRIX, map, game);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->matrix_map[i][j] != '\0')
			j++;
		if (j != map->columns)
			free_struct_map_and_exit(ERROR_IN_MATRIX, map, game);
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

static void	aux_check_player_exit_coins(t_map *map, int i, int j)
{
	if (map->matrix_map[i][j] == PLAYER)
		map->players ++;
	else if (map->matrix_map[i][j] == COLLECTIONABLE)
		map->coins ++;
	else if (map->matrix_map[i][j] == EXIT_GAME)
		map->exits ++;
}

void	check_minim_items_in_map(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 1;
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
	if (map->players != 1 || map->coins < 1 || map->exits != 1)
		free_struct_map_and_exit(ERROR_ITEMS_IN_MAP, map, game);
	get_positions_player_and_exit(map);
}
