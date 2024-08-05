/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/06 01:03:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/so_long.h"

int	main(int ac, char **av)
{
	printf("Hello, World!\n");
	if (ac == 2)
	{
		if (validate_filename_map(av))
			ft_printf("file extension Ok\n");
		else
			ft_printf("file no compatible\n");

	}
	return (0);
}
