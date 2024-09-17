/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:47:55 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/17 15:38:51 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

static void	draw_player_sprite_direction(t_game *game, int x, int y)
{
	if (game->player_sprite == LEFT_POSITION)
		put_image_to_window(game, game->player_left.xpm_ptr, x, y);
	else if (game->player_sprite == RIGHT_POSITION)
		put_image_to_window(game, game->player_right.xpm_ptr, x, y);
	else if (game->player_sprite == BACK_POSITION)
		put_image_to_window(game, game->player_back.xpm_ptr, x, y);
	else if (game->player_sprite == FRONT_POSITION)
		put_image_to_window(game, game->player_front.xpm_ptr, x, y);
}

void	render_sprite_by_title(t_game *game, char player_pos, int x, int y)
{
	if (player_pos == WALL)
		put_image_to_window(game, game->wall.xpm_ptr, x, y);
	else if (player_pos == FLOOR)
		put_image_to_window(game, game->floor.xpm_ptr, x, y);
	else if (player_pos == EXIT_GAME)
		put_image_to_window(game, game->exit_open.xpm_ptr, x, y);
	else if (player_pos == PLAYER)
	{
		put_image_to_window(game, game->player_front.xpm_ptr, x, y);
		draw_player_sprite_direction(game, x, y);
	}
	else if (player_pos == COLLECTIONABLE)
		put_image_to_window(game, game->coins.xpm_ptr, x, y);
}

void	render_full_map_sprites(t_game *game, int i, int j)
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
			render_sprite_by_title(game, game->map->matrix_map[i][j], x, y);
			j++;
		}
		i++;
	}
}

int	load_textures_game(t_game *game)
{
	if (check_img_xpm(game, &game->player_front.xpm_ptr, PLAYER_FRONT_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->player_left.xpm_ptr, PLAYER_LEFT_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->player_back.xpm_ptr, PLAYER_DOWN_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->player_right.xpm_ptr, PLAYER_RIGHT_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->floor.xpm_ptr, FLOOR_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->coins.xpm_ptr, COLLECT_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->wall.xpm_ptr, WALL_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->exit_open.xpm_ptr, EXIT_OPEN_XPM) == 1)
		return (1);
	if (check_img_xpm(game, &game->exit_closed.xpm_ptr, EXIT_CLOSED_XPM) == 1)
		return (1);
	return (0);
}
