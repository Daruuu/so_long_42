/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/23 01:02:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_connection(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf(ERROR_MEMORY_ALLOCATION);
		exit(EXIT_FAILURE);
	}
	game->win_ptr = mlx_new_window(game->win_ptr, game->map->rows * CELL_SIZE, \
		game->map->columns * CELL_SIZE, "So Long 42");
	if (game->win_ptr == NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		ft_printf(ERROR_MEMORY_ALLOCATION);
		exit(EXIT_FAILURE);
	}
//	img = mlx_new_image(mlx, 300, 300);
	mlx_loop(game->mlx_ptr);
}

t_image	new_image(void *mlx, char *path)
{
	t_image	image;

//	image.xpm_ptr = mlx_xpm_file_to_image(mlx, path, );

}
