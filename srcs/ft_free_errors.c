
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

void	free_struct_map_and_exit(t_map *map)
{
	int	i;

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
	if (message == 0)
	{
		free(ptr);
		ptr = NULL;
		exit (1);
	}
	ft_printf(message);
	free(ptr);
	ptr = NULL;
}