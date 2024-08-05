/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by anamedin          #+#    #+#             */
/*   Updated: 2024/08/05 16:46:04 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		// comprobar que el av[1] sea un mapa.ber
		if (validate_filename_map(av))
			ft_printf("file extension Ok\n");
		else
			ft_printf("file no compatible\n");

	}
	return (0);
}
