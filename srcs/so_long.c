/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:40:40 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/06 10:40:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game		*game;

	game = init_game();
	if (game == NULL)
	{
		free(game);
		exit(2);
	}
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1], &(game->map));
		init_game_windows_data(game);
		draw_map_sprites(game, 0, 0);
		mlx_key_hook(game->win_ptr, handle_event_keyboard, game);
		mlx_hook(game->win_ptr, 17, 0, close_window, game);
		mlx_loop(game->mlx_ptr);
	}
	free_struct_game(game, NULL);
	return (0);
}
