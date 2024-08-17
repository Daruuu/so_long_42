/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:23:11 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/16 14:46:34 by  dasalaza        ###   ########.fr       */
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

static int	check_all_ones(const char *line, t_map *map)
{
	int	j;

	j = 0;
	while (j < map->columns)
	{
		if (line[j] != WALL)
			return (1);
		j++;
	}
	return (0);
}

static int	check_first_and_last_line_map(char *av1, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = can_open_fd(av1);
	line = get_next_line(fd);
	if (check_all_ones(line, map) == 1)
	{
		free(line);
		return (1);
	}
	i = 2;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (i == map->rows && check_all_ones(line, map) == 1)
		{
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_columns_of_map(char *av1, t_map *map)
{
	int		fd;
	char	*line;
	int		len_line;
	int		i;

	fd = can_open_fd(av1);
	line = get_next_line(fd);
	map->columns = (int) ft_strlen(line) - 1;
	i = 0;
	while (line)
	{
		len_line = (int) ft_strlen(line);
		if (line[len_line - 1] == '\n')
			len_line = len_line - 1;
		if (len_line < 3 || len_line != map->columns || \
				(line[0] != WALL || line[len_line - 1] != WALL))
			return (1);
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
	if ((validate_filename_map(av1)) == 1)
		free_struct_map_and_exit(ERROR_INVALID_EXTENSION_MAP, n_map);

	if (check_columns_of_map(av1, n_map) == 1)
		free_struct_map_and_exit(ERROR_COLUMNS_MAP, n_map);

	if (check_first_and_last_line_map(av1, n_map) == 1)
		free_struct_map_and_exit(ERROR_ROWS_MAP, n_map);

	ptr_map = get_map_from_file(av1);
	if (ptr_map == NULL)
	{
		free(ptr_map);
		free_struct_map_and_exit(NULL, n_map);
	}
	add_map_to_matrix(ptr_map, n_map);
//	free_ptr(NULL, ptr_map);
	check_minim_items_in_map(n_map);
	flood_fill(n_map, n_map->player_pos.x, n_map->player_pos.y);
}
