/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/06 16:59:13 by  dasalaza        ###   ########.fr       */
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
		ft_printf("%s",av[i]);
		i++;
	}
}

void	get_map_from_file(char **av, int *num_lines)
{
	int		fd;
	char	**map;
	char	*line;
	int		lines_allocates;

	map = NULL;
	*num_lines = 0;
	lines_allocates = 3;
	map = (char **) malloc(lines_allocates * sizeof(char *));
	if_not_exist_free_pointer(map);

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error read fd\n");
		// free(map);
		return ;
	}
	lines_map = 0;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (*num_lines >= lines_allocated)
		{

		}
		map = get_next_line(fd);
	}
	// print_map(av[1]);
	close(fd);
	// free(map);
	// ft_printf("Len map: %s \n", lines_map);
}

// static int	is_empty_map(char **av)
// {
	
// }

void	all_validations(char **av)
{
	if (validate_filename_map(av) == 1)
		ft_printf("file extension Ok\n");
	else
		ft_printf("file no compatible\n");
	get_map_from_file(av);
	
}
