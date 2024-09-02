/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:36:22 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/02 12:52:41 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:31:20 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/17 19:48:05 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_and_message(char *message)
{
	ft_printf(message);
	exit(2);
}

void	free_ptr(char *message, char *ptr)
{
	if (message != 0)
		ft_printf(message);
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	exit (2);
}

void	free_map_copy(t_map *map_copy, char *message)
{
	int	i;

	if (message != NULL)
		ft_printf(message);
	if (map_copy != NULL && map_copy->matrix_map != NULL)
	{
		i = 0;
		while (i < map_copy->rows)
		{
			free(map_copy->matrix_map[i]);
			i++;
		}
		free(map_copy->matrix_map);
	}
	free(map_copy);
}

void	free_struct_map_and_exit(char *message, t_map *map)
{
	free_map_copy(map, message);
	exit(2);
}

void	free_struct_game(t_game *game)
{
	free_map_copy(game->map, NULL);
	if (game->mlx_ptr != NULL || game->win_ptr)
	{
		free(game->mlx_ptr);
		free(game->win_ptr);
	}
	free(game);
}
