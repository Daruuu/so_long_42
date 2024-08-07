/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:19:57 by dasalaza          #+#    #+#             */
/*   Updated: 2024/08/07 18:00:41 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t  get_block_size_ptr(void *ptr);
/*Recreate realloc
se utiliza para cambiar un bloque de memoria previamente creado con
malloc o calloc
Aumentar o disminuir el tamaño del bloque.
mover el bloque a una nueva ubicacion copiando el contenido anterior.

Pasos:
    
*/
// char **new_map =

// realloc(map, lines_allocated * sizeof(char *));
void    *ft_realloc(void *ptr, size_t new_size)
{
    void    *new_ptr;
    size_t  old_size_ptr;
    size_t  new_size_ptr;

    if(ptr == NULL)
        return (malloc(new_size));
    if(new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(new_size);
    if (!ptr)
        return(NULL);
    old_size_ptr = get_block_size_ptr(ptr);
    new_size_ptr = old_size_ptr - new_size;
    // (destino, srouce, size)
    ft_memcpy(new_ptr, ptr, new_size_ptr);
    free(ptr);
    return (new_ptr);
}

size_t  get_block_size_ptr(void *ptr)
{
    size_t  *len_ptr;

    if (!ptr)
        return (0);
    len_ptr = (size_t *)ptr - 1; 
    return (*len_ptr);
}