/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:39:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/03 13:16:23 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/so_long.h"

int	main(int ac, char **av)
{
	printf("Hello, World!\n");
	if (ac == 2)
	{
		validate_filename_map(av[1]);
		// comprobar que el av[1] sea un mapa.ber

	}

	return (0);
}
