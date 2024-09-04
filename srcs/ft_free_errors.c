/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:40:44 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/04 22:33:58 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_and_message(char *message)
{
	ft_printf(message);
	exit(2);
}

void	free_ptr(char *message, char *ptr)
{
	if (message != 0)
		ft_printf(message);
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	exit (2);
}

void	free_map_copy(t_map *map_copy, char *message)
{
	int	i;

	if (message != NULL)
		ft_printf(message);
	if (map_copy != NULL)
	{
		i = 0;
		while (i < map_copy->rows)
		{
			free(map_copy->matrix_map[i]);
			i++;
		}
		free(map_copy->matrix_map);
	}
	free(map_copy);
}

void	free_struct_map_and_exit(char *message, t_map *map)
{
	free_map_copy(map, message);
	exit(2);
}
void	free_game_ptr(t_game *game, char* message)
{
	if (message)
		ft_printf(message);
	if (game->win_ptr)
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
	}
	if (game->map)
		free_map_copy(game->map, message);
}

void	free_struct_game(t_game *game, char* message)
{
	free_map_copy(game->map, message);
	free_images_xpm(game);
	if (game->mlx_ptr != NULL && game->win_ptr != NULL)
	{
		free(game->mlx_ptr);
		free(game->win_ptr);
	}
	mlx_destroy_display(game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game);
}
