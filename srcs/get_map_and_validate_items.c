/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/11 23:28:49 by dasalaza         ###   ########.fr       */
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
		ft_printf("error allocations\n");
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
	i = 0;
	while (map->matrix_map[i] != NULL)
		i++;
	if (map->rows != i)
		ft_printf("matrix no correct!!");
        //TODO: call free of matrix here
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->matrix_map[i][j] != '\n')
			j++;
		if (j != map->columns)
		{
			ft_printf("matrix COLUMNS not correct!!");
			//TODO: add free matrix error
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
		ft_printf("ERROR MINIM COINS OR MAX EXITS OR MAX PLAYERS");
		// free of structure and exit ERROR
	}
}