/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:08:01 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/08 10:36:45 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/07 18:18:37by dasalaza         ###   ########.fr       */
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

void	print_map(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		ft_printf("%s", av[i]);
		i++;
	}
}

int	check_walls_map(char *line);
/*
 * Pre: el parametro map debe venir inicializado
 *
 */
int	check_validations_map(char *av, t_map *map)
{
	int		fd;
	char	*line;
	int		len_line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_printf("error read fd\n");

	map->columns = -1;
	map->rows = 0;
	while ((line = get_next_line(fd)) != NULL)
	{

		len_line = ft_strlen(line) - 1;
		if ((len_line < 3) || (map->columns != -1 && len_line != map->columns)
			|| (check_walls_map(line) == 0))
		{
			ft_printf("error\n");
			exit(EXIT_FAILURE);
		}
		if (map->columns == -1)
			map->columns = len_line;
		map->rows = map->rows + 1;
	}
	close(fd);
	return (1);
}

/*
 * posible error si la linea no tiene '/n'
 */

int	check_walls_map(char *line)
{
	if (line == NULL)
		return (0);
	while (*line != '\n')
	{
		if (*line != WALL)
			return (0);
		line++;
	}
	return (1);
}

int	can_open_map(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("fd < 0\n");
		exit(1);
	}
	return (fd);
}

void	aux_validations(char **av)
{
	int	n_columns;

	if (validate_filename_map(av) == 1)
		ft_printf("file extension Ok\n");
	else
		ft_printf("file no compatible\n");
	n_columns = 0;
	if (check_validations_map(av[1], &n_columns) == 1)
		ft_printf("columns is: %d Ok\n", n_columns);
	else
		ft_printf("error columns\n");
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