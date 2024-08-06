#include "../include/so_long.h"

void    if_not_exist_free_pointer(char **ptr)
{
    if (!ptr)
    {
        free(ptr);
        ptr = NULL;
    }
    ft_printf("Error: Memory allocation !!\n");
}