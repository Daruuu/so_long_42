/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:58:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/20 17:51:45 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	initialize_game(int ac, char **av, t_game **game)
{
	if (ac != 2)
	{
		ft_printf("Error argc\n");
		return (1);
	}
	*game = init_game();
	if (*game == NULL)
	{
		free_game(*game, ERROR_MEMORY_ALLOCATION);
		return (1);
	}
	validate_file_and_edge_of_map(av[1], &((*game)->map), *game);
	return (0);
}

int	setup_window_and_run_game(t_game *game)
{
	if (init_game_windows_data(game) != 0)
	{
		free_game_complete(game);
		return (1);
	}
	render_full_map_sprites(game, 0, 0);
	mlx_key_hook(game->win_ptr, handle_event_keyboard, game);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (initialize_game(ac, av, &game) != 0)
		return (1);
	if (setup_window_and_run_game(game) != 0)
		return (1);
	free_game_complete(game);
	return (0);
}
