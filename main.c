/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/13 01:45:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/so_long.h"

int	main(int ac, char **av)
{
	// printf("Hello, World!\n");
	if (ac == 2)
	{
		validate_file_and_edge_of_map(av[1]);
	}
	return (0);
}
