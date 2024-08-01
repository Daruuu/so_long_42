/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:53:47 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/07 22:02:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (num_bytes > 0 && (!ft_strchr(buff_datos_leidos, '\n')))
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
			storage = ft_strjoin(storage, buff_datos_leidos, -1);
		}
	}
	free(buff_datos_leidos);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd] || (storage[fd] && !ft_strchr(storage[fd], '\n')))
		storage[fd] = ft_read_line_file(fd, storage[fd], 1);
	if (!storage[fd])
		return (NULL);
	line = ft_extract_line(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = ft_update_storage(storage[fd]);
	return (line);
}

/*
#include <stdio.h>
int	main()
{
	int		fd;
	int		fd2;
	char	*result;

	result = NULL;
	fd = open("fd.txt", O_RDONLY);
	fd2 = open("fd2.txt", O_RDONLY);
	printf("file 1 line 1: %s\n", get_next_line(fd));
	printf("file 2 line 1: %s\n", get_next_line(fd2));
	printf("file 1 line 2: %s\n", get_next_line(fd));
	printf("file 2 line 2: %s\n", get_next_line(fd2));
	printf("file 1 line 3: %s\n", get_next_line(fd));
	
	close(fd);
	close(fd2);
	return (0);
}
*/
