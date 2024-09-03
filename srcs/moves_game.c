/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:34:02 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/03 18:07:59y  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * function to finish game correct if all coins was taken
 */

static void	close_game(t_game *game)
{
	if (game->mlx_ptr && game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game->map->matrix_map);
	free(game);
	exit(0);
}

void	game_victory(t_game *game)
{
	free_game_complete(game);
	ft_printf(WIN_GAME " with %d moves\n", game->count_moves);
}

/*
 *	function to validate new move of the PLAYER
 *
*/

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->rows || new_y < 0 || \
		new_y >= game->map->columns)
		return ;
	if (game->map->matrix_map[new_x][new_y] == WALL)
		return ;
	if (game->map->matrix_map[new_x][new_y] == EXIT_GAME \
			&& game->map->coins == 0)
		game_victory(game);
	update_floor_or_coins(game, new_x, new_y);
}

void	update_floor_or_coins(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->map->player_pos.x;
	last_y = game->map->player_pos.y;
	if (game->map->matrix_map[new_x][new_y] == FLOOR || \
			game->map->matrix_map[new_x][new_y] == COLLECTIONABLE)
	{
		game->map->matrix_map[last_x][last_y] = FLOOR;
		if (game->map->matrix_map[new_x][new_y] == COLLECTIONABLE)
			game->map->coins --;
		/*	update new position of player	*/
		game->map->player_pos.x = new_x;
		game->map->player_pos.y = new_y;
		/*	update player	*/
		game->map->matrix_map[new_x][new_y] = PLAYER;
		game->count_moves ++;
		ft_printf("count moves: %d \n", game->count_moves);
		draw_map_sprites(game);
	}
}

int	handle_event_keyboard(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == UP)
		move_player(game, game->map->player_pos.x - 1, game->map->player_pos.y);
	else if (keysym == KEY_A || keysym == LEFT)
		move_player(game, game->map->player_pos.x, game->map->player_pos.y - 1);
	else if (keysym == KEY_S || keysym == DOWN)
		move_player(game, game->map->player_pos.x + 1, game->map->player_pos.y);
	else if (keysym == KEY_D || keysym == RIGHT)
		move_player(game, game->map->player_pos.x, game->map->player_pos.y + 1);
	else if (keysym == KEY_Q || keysym == ESC)
	{
		ft_printf(CLOSE_GAME);
		close_game(game);
	}
	return (0);
}
