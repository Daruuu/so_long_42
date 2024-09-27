/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:33 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/20 18:17:32 by  dasalaza        ###   ########.fr       */
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

// int	can_open_fd(char *path_map)
int	can_open_fd(char *path_map, t_game *game)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(ERROR_FD);
		free_game_complete(game);
	}
	return (fd);
}

int	close_window(t_game *game)
{
	if (game)
	{
		free_images_xpm(game);
		if (game->map)
		{
			free_map_copy(game->map, NULL);
		}
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			mlx_destroy_display(game->mlx_ptr);
		free(game);
		exit(0);
	}
	return (1);
}

// void	check_image_texture(t_game *game, void **image, char *path)
int	check_img_xpm(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf(ERROR_PUT_IMAGES);
		return (1);
	}
	return (0);
}

int	validate_filename_map(char *av1)
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
