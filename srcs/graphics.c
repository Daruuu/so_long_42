/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:47:55 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/06 11:55:04 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	draw_map_sprites(t_game *game, int i, int j)
{
	int	x;
	int	y;

	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			x = j * CELL_SIZE;
			y = i * CELL_SIZE;
			if (game->map->matrix_map[i][j] == WALL)
				put_image_to_window(game, game->wall.xpm_ptr, x, y);
			else if (game->map->matrix_map[i][j] == FLOOR)
				put_image_to_window(game, game->floor.xpm_ptr, x, y);
			else if (game->map->matrix_map[i][j] == EXIT_GAME)
				put_image_to_window(game, game->exit_open.xpm_ptr, x, y);
			else if (game->map->matrix_map[i][j] == PLAYER)
				put_image_to_window(game, game->player_front.xpm_ptr, x, y);
			else if (game->map->matrix_map[i][j] == COLLECTIONABLE)
				put_image_to_window(game, game->coins.xpm_ptr, x, y);
			j++;
		}
		i++;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_map_copy(game->map, NULL);
	free_images_xpm(game);
	free(game);
	exit(0);
	return (0);
}

void	load_textures_game(t_game *game)
{
	check_image_texture(game, &game->player_front.xpm_ptr, PLAYER_FRONT_XPM);
	check_image_texture(game, &game->player_left.xpm_ptr, PLAYER_LEFT_XPM);
	check_image_texture(game, &game->player_back.xpm_ptr, PLAYER_DOWN_XPM);
	check_image_texture(game, &game->player_right.xpm_ptr, PLAYER_RIGHT_XPM);
	check_image_texture(game, &game->floor.xpm_ptr, FLOOR_XPM);
	check_image_texture(game, &game->coins.xpm_ptr, COLLECT_XPM);
	check_image_texture(game, &game->wall.xpm_ptr, WALL_XPM);
	check_image_texture(game, &game->exit_open.xpm_ptr, EXIT_OPEN_XPM);
	check_image_texture(game, &game->exit_closed.xpm_ptr, EXIT_CLOSED_XPM);
}

void	check_image_texture(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
		free(image);
}
