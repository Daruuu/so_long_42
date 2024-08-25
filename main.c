/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/25 14:53:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_game		*game;

	ft_printf("Hello, World!\n");
	game = init_game();
	if (game == NULL)
	{
		free_struct_game(game);
		exit(2);
	}
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1], &(game->map));
//		print_map(game->map);
//		print_map_data(game->map);
	}

	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf(ERROR_MEMORY_ALLOCATION);
		exit(EXIT_FAILURE);
	}
//	game->win_ptr = mlx_new_window(game->win_ptr, game->map->rows * CELL_SIZE,
//		game->map->columns * CELL_SIZE, "So Long 42");
//	if (game->win_ptr == NULL)
//	{
//		mlx_destroy_display(game->mlx_ptr);
//		ft_printf(ERROR_MEMORY_ALLOCATION);
//		exit(EXIT_FAILURE);
//	}
//	img = mlx_new_image(mlx, 300, 300);
	ft_printf("Hello, World!\n");
//	mlx_loop(game->mlx_ptr);










//	free_struct_game(game);
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_game	*game;

	ft_printf("Hello, World!\n");
	game = init_game();
	if (game == NULL)
	{
		free_struct_game(game);
		exit(2);
	}
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1], &(game->map));
	}
//	print_map(game->map);
//	print_map_data(game->map);

	free_struct_game(game);
	return (0);
}
*/
