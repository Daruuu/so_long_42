/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/03 13:11:36 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_position	init_positions(void)
{
	t_position	new_positions;

	new_positions.x = 0;
	new_positions.y = 0;
	return (new_positions);
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

t_game	*init_game_map(void)
{
	t_game	*new_game;

	new_game = (t_game *) malloc(sizeof(t_game));
	if (new_game == NULL)
		return (NULL);
	new_game->mlx_ptr = NULL;
	new_game->win_ptr = NULL;
	new_game->count_moves = 0;
	new_game->map = NULL;
	return (new_game);
}

static void	init_images_game_to_null(t_game *game)
{
	game->wall.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->coins.xpm_ptr = NULL;
	game->exit_open.xpm_ptr = NULL;
	game->exit_closed.xpm_ptr = NULL;
	game->player_front.xpm_ptr = NULL;
	game->player_left.xpm_ptr = NULL;
	game->player_back.xpm_ptr = NULL;
	game->player_right.xpm_ptr = NULL;
}

void	init_game_windows_data(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error init mlx_ptr\n");
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map->columns * CELL_SIZE, \
	game->map->rows * CELL_SIZE, TITLE_WINDOWS);
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		ft_printf("Error init win_ptr\n");
		exit(EXIT_FAILURE);
	}
	init_images_game_to_null(game);
	load_textures_game(game);
}
