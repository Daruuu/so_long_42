/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:33 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/12 00:20:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	aux_check_all_ones(const char *line, t_map *map)
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

int	can_open_fd(char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		exit_and_message(ERROR_FD);
	return (fd);
}

int	close_window(t_game *game)
{
	free_images_xpm(game);
	mlx_destroy_display(game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_map_copy(game->map, NULL);
	free(game);
	return (1);
}

void	check_image_texture(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		free(image);
		ft_printf("error image texture creating !!!\n");
	}
	else
		return ;
}
