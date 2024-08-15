/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:23:11 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/16 01:34:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	validate_filename_map(char *av1)
{
	const char	*type_file;
	int			len_file;

	type_file = ".ber";
	len_file = (int) ft_strlen(av1);
	if (len_file < 4)
		return (1);
	if (ft_strncmp(av1 + len_file - 4, type_file, 4) != 0)
		return (1);
	return (0);
}

static int	check_first_and_last_line_map(char *line, int row, int total_rows)
{
	int	i;
	int	len;

	len = (int) ft_strlen(line);
	if (line[len - 1] == '\n')
		len --;
	if (row == 0 || row == total_rows - 1)
	{
		i = 0;
		while (i < len)
		{
			if (line[i] != WALL)
				return (1);
			i++;
		}
	}
	else
		if (line[0] != WALL || line[len - 1] != WALL)
			return (1);
	return (0);
}

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		exit_and_message("fd < 0");
	return (fd);
}
/*
 * NORMINNETE
*/

static int	check_edge_of_map(char *av1, t_map *map)
{
	int		fd;
	char	*line;
	int		len_line;
	int		i;

	fd = can_open_fd(av1);
	map->columns = -1;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		len_line = (int) ft_strlen(line);
		if (line[len_line - 1] == '\n')
			line[--len_line] = '\0';
		if (len_line < 3)
			exit_and_message("len line < 3");
		if (map->columns == -1)
			map->columns = len_line;
		else if (len_line != map->columns)
			exit_and_message("error map columns no OK\n");
		if (check_first_and_last_line_map(line, i, map->rows) == 1)
			exit_and_message("error walls map\n");
		map->rows ++;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}

void	validate_file_and_edge_of_map(char *av1)
{
	t_map	*n_map;
	char	*ptr_map;

	n_map = init_map();
	if (n_map == NULL)
		return ;
	if (!(validate_filename_map(av1)))
		free_struct_map_and_exit(ERROR_INVALID_EXTENSION_MAP, n_map);
	if (!check_edge_of_map(av1, n_map))
		free_struct_map_and_exit(ERROR_EDGE_MAP, n_map);
	ptr_map = get_map_from_file(av1);
	if (ptr_map == NULL)
		free_struct_map_and_exit(ERROR_LOADING_MAP, n_map);
	add_map_to_matrix(ptr_map, n_map);
	free_ptr(NULL, ptr_map);
	check_minim_items_in_map(n_map);
	flood_fill(n_map, n_map->player_pos.x, n_map->player_pos.y);
}
