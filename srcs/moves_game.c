/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:18:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/19 14:48:24 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_victory(t_game *game)
{
	ft_printf(WIN_GAME " with %d moves\n", game->count_moves);
	free_game_complete(game);
}

void	move_player(t_game *game, int new_x, int new_y, int player_sprite)
{
	if (new_x < 0 || new_x >= game->map->rows || new_y < 0 || \
		new_y >= game->map->columns)
		return ;
	if (game->map->matrix_map[new_x][new_y] == WALL)
		return ;
	game->player_sprite = player_sprite;
	if (game->map->matrix_map[new_x][new_y] == EXIT_GAME \
			&& game->map->coins == 0)
	{
		game_victory(game);
		return ;
	}
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
		game->map->player_pos.x = new_x;
		game->map->player_pos.y = new_y;
		game->map->matrix_map[new_x][new_y] = PLAYER;
		game->count_moves ++;
		ft_printf("count moves: %d \n", game->count_moves);
		render_full_map_sprites(game, 0, 0);
	}
}

int	handle_event_keyboard(int keysym, t_game *game)
{
	if (keysym == KEY_W || keysym == UP)
		move_player(game, game->map->player_pos.x - 1, \
		game->map->player_pos.y, BACK_POSITION);
	else if (keysym == KEY_A || keysym == LEFT)
		move_player(game, game->map->player_pos.x, \
		game->map->player_pos.y - 1, LEFT_POSITION);
	else if (keysym == KEY_S || keysym == DOWN)
		move_player(game, game->map->player_pos.x + 1, \
		game->map->player_pos.y, FRONT_POSITION);
	else if (keysym == KEY_D || keysym == RIGHT)
		move_player(game, game->map->player_pos.x, \
		game->map->player_pos.y + 1, RIGHT_POSITION);
	else if (keysym == KEY_Q || keysym == ESC)
	{
		ft_printf(EXIT_GAME_MESSAGE);
		free_game_complete(game);
	}
	return (0);
}
