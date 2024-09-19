/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:44:30 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/19 12:37:38 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game_complete(t_game *game)
{
	if (game)
	{
		free_images_xpm(game);
		if (game->map)
		{
			free_map_copy(game->map, NULL);
		}
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
			mlx_destroy_display(game->mlx_ptr);
		// free(game);
	}
	free(game);
	exit(1);
}

void	free_images_xpm(t_game *game)
{
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->coins.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
	if (game->exit_open.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
	if (game->exit_closed.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	if (game->player_front.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	if (game->player_left.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	if (game->player_right.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	if (game->player_back.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
}

//	call if game is nullllllllll
void	free_game(t_game *game, char *message)
{
	if (message)
		ft_printf(message);
	if (game->map)
		free_map_copy(game->map, message);
	free(game);
}
