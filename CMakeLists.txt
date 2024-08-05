cmake_minimum_required(VERSION 3.28)

# cmake_minimum_required(VERSION 3.28)
project(so_long_42 C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long_42 main.c
#       HEADERS
        include/so_long.h
        libs/printf/ft_printf.h
#       LIBFT
        libs/libft/ft_strlen.c
        libs/libft/ft_strncmp.c
#        PRINTF
        libs/printf/ft_printf.c
        libs/printf/ft_put_ptr.c
        libs/printf/ft_put_uint_nbr.c
        libs/printf/ft_putchar_n.c
        libs/printf/ft_puthexa_nbr.c
        libs/printf/ft_putnbr_n.c
        libs/printf/ft_putstr.c
#       SO_LONG
        srcs/validations_map.c

)