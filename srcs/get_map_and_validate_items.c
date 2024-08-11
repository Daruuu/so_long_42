/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_and_validate_items.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:02:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/11 19:40:35 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char    *get_map_from_file(char *path)
{
    char    *new_map;
    int     fd;
    char    buffer;
    int     i;

    fd = can_open_fd(path);
    i = 0;
    while (read(fd, &buffer, 1))
        i ++;
    close(fd);
    if (i == 0)
        exit_and_message("empty file\n");
    new_map = (char *) malloc(i + 1);
    if (!new_map)
        ft_printf("error allocations\n");
    fd = open(path, O_RDONLY);
    read (fd, new_map, i);
    new_map[i] = '\0';
    close(fd);
    return (new_map);
}

void    add_map_to_matrix(char *map, t_map *map)
{
    int i;
    int j;
    map->matrix = ft_split(map, "\n");
    while (map->matrix[i] != '\0')
        i++;
    if (map->rows != i)
        ft_printf("matrix no correct!!");
        //TODO: call free of matrix here
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (map->matrix[i][j] != '\n')
            j++;
        if (j != map->columns)
        {
            ft_printf("matrix COLUMNS not correct!!");
            // TODO: add free matrix error

        }

        i ++;

    }

}

void    check_minim_items_in_map(char *map, t_map *map)
