/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:05:46 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/14 19:24:51 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			ft_putchar(map->matrix_map[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	ft_putchar('\n');
}
