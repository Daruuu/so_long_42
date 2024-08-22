/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:51:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/20 16:37:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// -----------------------------------------------------------------------------

void	init_graphics(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "So Long 42");
	img = mlx_new_image(mlx, 300, 300);
	mlx_loop(mlx);
}
