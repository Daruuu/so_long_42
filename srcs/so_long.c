/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:40:44 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/04 18:51:52 by dasalaza         ###   ########.fr       */
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
		// free_struct_game(game, NULL);
		exit(2);
	}
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1], &(game->map));
		/*
		if (game->map->columns >= 1080 || game->map->rows >= 1920)
			ft_printf("Error: Map is too large\n");
		*/
		init_game_windows_data(game);
		draw_map_sprites(game);
		mlx_key_hook(game->win_ptr, handle_event_keyboard, game);
		mlx_hook(game->win_ptr, 17, 0, close_window, game);
		mlx_loop(game->mlx_ptr);
	}
	free_struct_game(game, NULL);
	// free(game);
	return (0);
}
