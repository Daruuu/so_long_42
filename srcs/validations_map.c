/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:32:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/12 00:12:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static int	check_first_and_last_line_map(char *av1, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = can_open_fd(av1);
	line = get_next_line(fd);
	if (line == NULL || aux_check_all_ones(line, map) == 1)
	{
		free_and_close(line, fd);
		return (1);
	}
	i = 2;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (i == map->rows && line && aux_check_all_ones(line, map) == 1)
		{
			free_and_close(line, fd);
			return (1);
		}
		i++;
	}
	free_and_close(line, fd);
	return (0);
}

int	check_all_line(char *line, int len_line, t_map *map)
{
	int	i;

	if (len_line < 3 || len_line != map->columns || \
		(line[0] != WALL || line[len_line - 1] != WALL))
	{
		return (1);
	}
	i = 0;
	while (i < len_line)
	{
		if (line[i] != WALL && \
			line[i] != PLAYER && \
			line[i] != COLLECTIONABLE && \
			line[i] != EXIT_GAME && \
			line[i] != FLOOR)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_columns_of_map(char *av1, t_map *map, int i)
{
	int		fd;
	char	*line;
	int		len_line;

	fd = can_open_fd(av1);
	line = get_next_line(fd);
	if (!line)
		free_exit_file_columns_map(line, ERROR_INVALID_MAP);
	map->columns = (int) ft_strlen(line) - 1;
	while (line)
	{
		len_line = (int) ft_strlen(line);
		if (line[len_line - 1] == '\n')
			len_line = len_line - 1;
		if (check_all_line(line, len_line, map))
		{
			free_exit_file_columns_map(line, ERROR_INVALID_MAP);
			return (1);
		}
		map->rows ++;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (0);
}

void	validate_file_and_edge_of_map(char *av1, t_map **map)
{
	char	*ptr_map;

	*map = init_map();
	if (*map == NULL)
	{
		free_map_copy(*map, NULL);
		return ;
	}
	if (validate_filename_map(av1) == 1)
		free_struct_map_and_exit(ERROR_INVALID_EXTENSION_MAP, *map);
	if (check_columns_of_map(av1, *map, 0) == 1)
		free_struct_map_and_exit(ERROR_COLUMNS_MAP, *map);
	if (check_first_and_last_line_map(av1, *map) == 1)
		free_struct_map_and_exit(ERROR_ROWS_MAP, *map);
	ptr_map = get_map_from_file(av1);
	if (ptr_map == NULL)
		free_struct_map_and_exit(NULL, *map);
	add_map_to_matrix(ptr_map, *map);
	check_minim_items_in_map(*map);
	if (flood_fill(*map, (**map).player_pos.x, (**map).player_pos.y) == 1)
	{
		free(ptr_map);
		free_map_copy(*map, ERROR_INVALID_MAP);
		exit(2);
	}
}
