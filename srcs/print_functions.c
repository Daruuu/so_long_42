/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:12:31 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/16 13:15:10 by  dasalaza        ###   ########.fr       */
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
	ft_printf("PRINT MATRIX MAP:\n");
	ft_printf("----------------------\n");
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
	ft_printf("----------------------\n");
}

void	print_map_data(t_map *map)
{
	ft_printf("DATA OF MAP:\n");
	ft_printf("----------------------\n");
	ft_printf("rows: %d\n", map->rows);
	ft_printf("columns: %d\n", map->columns);
	ft_printf("coins: %d\n", map->coins);
	ft_printf("exits: %d\n", map->exits);
	ft_printf("players: %d\n", map->players);
	ft_printf("player_pos.x: %d\n", map->player_pos.x);
	ft_printf("player_pos.y: %d\n", map->player_pos.y);
	ft_printf("exit_pos.x: %d\n", map->exit_pos.x);
	ft_printf("exit_pos.y: %d\n", map->exit_pos.y);
	ft_printf("----------------------\n");
}

void	free_and_close(char *line, int fd)
{
	free(line);
	close(fd);
}

void	free_exit_file_columns_map(char *line, char *message)
{
	ft_printf(message);
	free(line);
	return ;
}
