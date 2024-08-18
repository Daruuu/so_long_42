/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/13 19:53:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	ft_printf("Hello, World!\n");
	t_game	*game;

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
