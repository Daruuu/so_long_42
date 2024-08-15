
#include "../include/so_long.h"

void	if_not_exist_free_pointer(char **ptr)
{
	if (!ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	ft_printf("Error: memory allocation\n");
}

void	exit_and_message(char *message)
{
	ft_printf(message);
	exit(1);
}

void free_struct_map_and_exit(char *message, t_map *map)
{
	int	i;

	if (message != NULL)
		ft_printf(message);
	if (map != NULL)
	{
		if (map->matrix_map != NULL)
		{
			i = 0;
			while (i < map->rows)
			{
				free(map->matrix_map[i]);
				i++;
			}
			free(map->matrix_map);
		}
	}
	free(map);
	exit(1);
}

void	free_matrix_and_exit(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(*map);
	exit(1);
}

void	free_ptr(char *message, char *ptr)
{
	if (message != 0)
		ft_printf(message);
	if (ptr != NULL)
	{
		free(ptr);
//		ptr = NULL;
	}
	exit (1);
}

void free_map_copy(t_map *map_copy, char *message)
{
	int	i;

	if (message != NULL)
		ft_printf(message);
	if (map_copy->matrix_map != NULL)
	{
		i = 0;
		while (i < map_copy->rows)
		{
			free(map_copy->matrix_map[i]);
			i++;
		}
		free(map_copy->matrix_map);
		free(map_copy);
	}
}
