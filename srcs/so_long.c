/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:44:02 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/10 00:56:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game		*game;

	if (ac != 2)
	{
		ft_printf("Error argc\n");
		exit(2);
	}
	else
	{
		game = init_game();
		if (game == NULL)
		{
			free(game);
			exit(2);
		}
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
