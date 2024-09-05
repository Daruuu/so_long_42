/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:47:55 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/05 20:43:49 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcel>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:40:44 by dasalaza          #+#    #+#             */
/*   Updated: 2024/09/05 00:13:11 by dasalaza         ###   ########.fr       */
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
	// printf("Entro aqui\n");
	if (message != NULL)
		ft_printf(message);
	i = 0;
	if (map_copy != NULL)
	{
		if (map_copy->matrix_map != NULL)
		{
			// printf("map copy no e snull\n");
			i = 0;
			while (map_copy->matrix_map[i] != NULL)
			{
				// printf("free col %d\n", i);
				free(map_copy->matrix_map[i]);
				i++;
			}
			free(map_copy->matrix_map);
		}
		free(map_copy);
	}
}

void	free_struct_map_and_exit(char *message, t_map *map)
{
	free_map_copy(map, message);
	exit(1);
}
