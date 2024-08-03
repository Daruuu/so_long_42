/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:10:31 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/03 14:44:58 by  dasalaza        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int validate_filename_map(char **av)
{
    char    *type_file;
    int     len_file;
    char    *result;
    int     i;

    type_file = ".ber";
    len_file =  ft_strlen(av[1]);
    result = ft_strnstr(av[1], type_file, len_file);
    i = 0;
    while (result && type_file)
    {
        if (result[i] != type_file[i])
            return (0);
        i++;
    }
    return (1);
}
