/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:26:32 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/12 17:13:19 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	if_not_exist_free_pointer(char **ptr)
{
	if (!ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	ft_printf("Error: memory allocation\n");
}

void	exit_and_message(char *message)
{
	ft_printf(message);
	exit(1);
}

void	free_struct_map_and_exit(t_map *map)
{
	int	i;

	if (map != NULL)
	{
		if (map->matrix_map != NULL)
		{
			i = 0;
			while (i < map->rows)
			{
				free(map->matrix_map[i]);
				i++;
			}
			free(map->matrix_map);
		}
	}
	free(map);
	exit(1);
}
