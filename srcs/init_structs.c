/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/01 18:10:38 by dasalaza         ###   ########.fr       */
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
	new_game->player_sprite = 0;

	new_game->map = NULL;
	return (new_game);
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
	load_textures_game(game);
}

void	check_image_texture(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		free(image);
		ft_printf("Error en init images!\n");
	}
}
