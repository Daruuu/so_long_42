/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:20:51 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/11 00:23:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	validate_filename_map(char **av)
{
	const char	*type_file;
	int			len_file;

	type_file = ".ber";
	len_file = (int) ft_strlen(av[1]);
	if (len_file < 4)
		return (0);
	if (ft_strncmp(av[1] + len_file - 4, type_file, 4) == 0)
		return (1);
	return (0);
}

int	check_walls_map(char *line, int row, int total_rows);
int	can_open_fd(char *path_map);
/*
 * Pre: el parametro map debe venir inicializado
 */

int	check_validations_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
	int		len_line;
	int		i;

	fd = can_open_fd(av);
	map->columns = -1;
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		len_line = (int) ft_strlen(line) - 1;
		if (len_line < 3)
		{
			ft_printf("len line < 3\n");
			exit(0);
		}
		else if (map->columns != -1 && len_line != map->columns)
		{
			ft_printf("columns: %d\n", map->columns);
			ft_printf("error map columns no OK\n");
			exit(0);
		}
		else if (check_walls_map(line, i, map->rows) == 0)
		{
			ft_printf("error walls map\n");
			exit(0);
		}
		if (map->columns == -1)
			map->columns = len_line;
		map->rows = map->rows + 1;
		ft_printf("PRINT LINE: %d\n%s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

/*
 * posible error si la linea no tiene '/n'
 */

int	check_walls_map(char *line, int row, int total_rows)
{
	int	i;

	if (row == 0 || row == total_rows - 1)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] != WALL)
				return (0);
			i++;
		}
	}
	else
		if (line[0] != WALL || line[ft_strlen(line) - 2] != WALL)
			return (0);
	return (1);
}

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd < 0\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	aux_validations(char **av)
{
	t_map	*new_map;

	new_map = init_map();
	if (validate_filename_map(av) == 1)
	{
		ft_printf("file extension Ok\n");
		if (check_validations_map(av[1], new_map) == 1)
		{
			ft_printf("columns map: %d \n", new_map->columns);
			ft_printf("rows map: %d \n", new_map->rows);
		}
	}
	else
	{
		ft_printf("file no compatible\n");
		ft_printf("error columns\n");
	}
}

/*
void	get_map_from_file(char **av)
{
	int		fd;
	char	**map;
	char	*line;
	int		lines_allocates;
	int		len_line;

	map = NULL;
	lines_allocates = 1;
	map = (char **) malloc(lines_allocates * sizeof(char *));

	if_not_exist_free_pointer(map);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error read fd\n");
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		len_line = ft_strlen(line);
		// if (*num_lines >= lines_allocated)
		{

		}
		map = get_next_line(fd);
	}
	print_map(av[1]);
	close(fd);
	// free(map);
	// ft_printf("Len map: %s \n", lines_map);
}
*/
/*
 static int	is_empty_map(char **av)
 {

 }
*/
