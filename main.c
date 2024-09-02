/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/02 00:37:42 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_game		*game;

	game = init_game_map();
	if (game == NULL)
	{
		free_struct_game(game);
		exit(2);
	}
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1], &(game->map));
		init_game_windows_data(game);
		draw_map_sprites(game);

		mlx_key_hook(game->win_ptr, handle_event_keyboard, game);
		mlx_hook(game->win_ptr, 17, 0, close_window, game);
		mlx_loop(game->mlx_ptr);
	}
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_game	*game;

	ft_printf("Hello, World!\n");
	game = init_game_map();
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

/*
 * // Este codigo pinta pixeles en una pantalla 300x300. 30/08/2024
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	int i = 0;
	while (i < 100) {
		int j = 0;
		while (j < 100) {
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	i = 100;
	while (i < 200) {
		int j = 100;
		while (j < 200) {
			my_mlx_pixel_put(&img, i, j, 0xffa4ffa4);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
