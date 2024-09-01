/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/01 18:01:34 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	draw_map_sprites(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
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
	exit(0);
}

void	load_textures_game(t_game *game)
{
	check_image_texture(game, &game->player_front.xpm_ptr, PLAYER_XPM);

	check_image_texture(game, &game->floor.xpm_ptr, FLOOR_XPM);
	check_image_texture(game, &game->coins.xpm_ptr, COLLECT_XPM);
	check_image_texture(game, &game->wall.xpm_ptr, WALL_XPM);

	check_image_texture(game, &game->exit_open.xpm_ptr, EXIT_OPEN_XPM);
	check_image_texture(game, &game->exit_closed.xpm_ptr, EXIT_CLOSED_XPM);
}
