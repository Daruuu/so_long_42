/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/25 14:12:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:20:51 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/12 19:38:29 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_position	init_positions(void)
{
	t_position	new_positions;

	new_positions.x = 0;
	new_positions.y = 0;
	return (new_positions);
}

t_image	*init_window(void)
{
	t_image	*s_image;

	s_image = (t_image *) malloc(sizeof(t_image));
	s_image->xpm_ptr = NULL;
	s_image->win_pos = init_positions();
	return (s_image);
}

t_map	*init_map(void)
{
	t_map	*new_map;

	new_map = (t_map *) malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->matrix_map = NULL;
	new_map->rows = 0;
	new_map->columns = 0;
	new_map->coins = 0;
	new_map->exits = 0;
	new_map->players = 0;
	new_map->player_pos = init_positions();
	new_map->exit_pos = init_positions();
	return (new_map);
}

t_game	*init_game(void)
{
	t_game	*new_game;

	new_game = (t_game *) malloc(sizeof(t_game));
	if (new_game == NULL)
		return (NULL);
	new_game->mlx_ptr = NULL;
	new_game->win_ptr = NULL;

	new_game->count_moves = 0;
	new_game->player_sprite = 0;

	new_game->map = NULL;

	new_game->wall.xpm_ptr = NULL;
	new_game->floor.xpm_ptr = NULL;
	new_game->coins.xpm_ptr = NULL;

	new_game->open_exit.xpm_ptr = NULL;
	new_game->exit_closed.xpm_ptr = NULL;

	new_game->player_front.xpm_ptr = NULL;
	new_game->player_left.xpm_ptr = NULL;
	new_game->player_right.xpm_ptr = NULL;
	new_game->player_back.xpm_ptr = NULL;

	return (new_game);
}
