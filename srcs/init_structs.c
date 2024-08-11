/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:20:51 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/11 17:22:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_position	init_positions(void)
{
	t_position	new_positions;

	new_positions.x = 0;
	new_positions.y = 0;
	return (new_positions);
}

t_image	init_window(void)
{
	t_image	s_image;

	s_image.xpm_ptr = NULL;
	s_image.win_pos = init_positions();
	return (s_image);
}

t_map	*init_map(void)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->matrix_map = NULL;
	new_map->rows = 0;
	new_map->columns = 0;
	new_map->coins = 0;
	new_map->exits = 0;
	new_map->players = 0;
	new_map->player_pos = init_positions();
	return (new_map);
}

t_game	init_game(void)
{
	t_game	new_game;
	// t_image	new_image;

	new_game.mlx_ptr = NULL;
	new_game.win_ptr = NULL;
	new_game.count_moves = 0;
	new_game.player_sprite = 0;
	return (new_game);
}
