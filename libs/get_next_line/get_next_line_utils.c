/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:14 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/05 14:37:44 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2, int i)
{
	char	*new_ptr;
	int		j;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		if (!str1)
			return (0);
		str1[0] = '\0';
	}
	new_ptr = malloc (sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_ptr)
	{
		free(str1);
		return (NULL);
	}
	while (str1[++i])
		new_ptr[i] = str1[i];
	j = -1;
	while (str2[++j])
		new_ptr[i + j] = str2[j];
	new_ptr[i + j] = '\0';
	free(str1);
	return (new_ptr);
}

char	*ft_strchr_gnl(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (&str[i]);
}

/*
 * esta funcion extrae un string 
 * el STORAGE  
 * extraemos si encontramos un  '/0' en el archivo,
 * cuando tengamos esa longitud
 * rellenamos la LINEA a devolver con el contenido STORAGE
 * hasta la longitud que hemos obtenido en LINE_COPY.
*/

char	*ft_extract_line(char *storage)
{
	int		size_line;
	char	*line_return;
	int		i;

	i = 0;
	size_line = 0;
	if (storage[0] == '\0')
		return (NULL);
	while (storage[size_line] && storage[size_line] != '\n')
		size_line++;
	if (storage[size_line] == '\n')
		size_line++;
	line_return = (char *) malloc((size_line + 1) * sizeof(char));
	if (!line_return)
		return (NULL);
	i = 0;
	while (i < size_line)
	{
		line_return[i] = storage[i];
		i++;
	}
	line_return[i] = '\0';
	return (line_return);
}
/*
char	*ft_free_line(char *storage)
{
	free(storage);
	storage = NULL;
	return (NULL);
}
*/

char	*ft_update_storage(char *storage)
{
	char	*ptr_newline;
	char	*rest_of_line;
	int		size_rest_of_line;
	int		i;

	ptr_newline = ft_strchr_gnl(storage, '\n');
	if (!ptr_newline)
	{
		free(storage);
		return (NULL);
	}
	size_rest_of_line = ft_strlen(ptr_newline + 1);
	rest_of_line = (char *) malloc(size_rest_of_line * sizeof(char) + 1);
	if (!rest_of_line)
	{
		free(storage);
		return (NULL);
	}
	i = -1;
	while (++i < size_rest_of_line)
		rest_of_line[i] = ptr_newline[i + 1];
	rest_of_line[i] = '\0';
	free (storage);
	storage = rest_of_line;
	return (storage);
}
