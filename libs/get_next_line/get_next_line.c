/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  dasalaza < dasalaza@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/06 14:19:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_aux_free(char *buffer, char *storage)
{
	free(storage);
	free(buffer);
}

char	*ft_read_line_file(int fd, char *storage, int num_bytes)
{
	char	*buff_datos_leidos;

	buff_datos_leidos = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_datos_leidos)
	{
		free(storage);
		return (NULL);
	}
	buff_datos_leidos[0] = '\0';
	while (num_bytes > 0 && (!ft_strchr_gnl(buff_datos_leidos, '\n')))
	{
		num_bytes = read(fd, buff_datos_leidos, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			ft_aux_free(buff_datos_leidos, storage);
			return (NULL);
		}
		else
		{
			buff_datos_leidos[num_bytes] = '\0';
			storage = ft_strjoin_gnl(storage, buff_datos_leidos, -1);
		}
	}
	free(buff_datos_leidos);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr_gnl(storage, '\n')))
		storage = ft_read_line_file(fd, storage, 1);
	if (!storage)
		return (NULL);
	line = ft_extract_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_update_storage(storage);
	return (line);
}
/*
#include <stdio.h>

int	main()
{
	int		fd;
	char	*result;

	result = NULL;
	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opened file");
		return (1);
	}
	result = get_next_line(fd);
	while (result)
	{
		printf("contenido del archivo: |%s\n|", result);
	}
	close(fd);
	return (0);
}
*/
