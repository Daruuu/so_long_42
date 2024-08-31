/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/31 15:43:34 by dasalaza         ###   ########.fr       */
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
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->columns * CELL_SIZE,game->map->rows * CELL_SIZE, TITLE_WINDOWS);

	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		ft_printf("Error init win_ptr\n");
		exit(EXIT_FAILURE);
	}
	load_textures_game(game);
//	identify_images(game);
}

static void	check_image_texture(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf("Error en init images!\n");
	}
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

/*
static void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &image, x, y);
}
*/

void	put_image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	identify_images(t_game *game)
{
	int i, j;
	int x, y;

	for (i = 0; i < game->map->rows; i++)
	{
		for (j = 0; j < game->map->columns; j++)
		{
			x = j * CELL_SIZE;
			y = i * CELL_SIZE;

			// Determina qué imagen poner dependiendo del contenido del mapa
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
		}
	}
}

/*
void	identify_images(t_game *game)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->columns)
		{
			x = i * CELL_SIZE;
			y = j * CELL_SIZE;
			if (game->map->matrix_map[i][j] == WALL)
				mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &game->wall.xpm_ptr, x, y);
			if (game->map->matrix_map[i][j] == FLOOR)
				mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &game->floor.xpm_ptr, x, y);
			if (game->map->matrix_map[i][j] == EXIT_GAME)
				mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &game->exit_open.xpm_ptr, x, y);
			if (game->map->matrix_map[i][j] == PLAYER)
				mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &game->player_front.xpm_ptr, x, y);
			if (game->map->matrix_map[i][j] == COLLECTIONABLE)
				mlx_put_image_to_window(&game->mlx_ptr, &game->win_ptr, &game->coins.xpm_ptr, x, y);
			j++;
		}
		i++;
	}
}
*/

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}
