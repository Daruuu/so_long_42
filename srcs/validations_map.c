/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/05 23:17:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_filename_map(char **av)
{
	const char	*type_file;
	int			len_file;

	type_file = ".ber";
	len_file = (int) ft_strlen(av[1]);
	if (len_file < 4)
		return (0);
	if (ft_strncmp(av[1] + len_file - 4, type_file, 4) == 0)
		return (1);
	return (0);
}
