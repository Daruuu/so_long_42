/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/22 17:37:33 by dasalaza         ###   ########.fr       */
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
		print_map(game->map);
		print_map_data(game->map);
	}
	//	CALL CONNECTION
	init_connection(game);

	free_struct_game(game);
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
