cmake_minimum_required(VERSION 3.22)

project(so_long_42 C)

set(CMAKE_C_STANDARD 99)

# Comando para compilar libmlx.a
add_custom_target(libmlx ALL
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs/minilibx-linux
        COMMENT "Compilando libmlx.a"
)

# Añadir el ejecutable
add_executable(so_long_42 srcs/so_long.c
        # HEADERS
        includes/so_long.h
        includes/aux_so_long.h
        libs/libft/libft.h
        libs/printf/ft_printf.h
        libs/get_next_line/get_next_line.h
        libs/minilibx-linux/mlx.h
        libs/minilibx-linux/mlx_int.h
        # LIBFT
        libs/libft/ft_strlen.c
        libs/libft/ft_strncmp.c
        libs/libft/ft_memcpy.c
        libs/libft/ft_split.c
        libs/libft/ft_strchr.c
        libs/libft/ft_substr.c
        libs/libft/ft_strdup.c
        # PRINTF
        libs/printf/ft_printf.c
        libs/printf/ft_put_ptr.c
        libs/printf/ft_put_uint_nbr.c
        libs/printf/ft_putchar_n.c
        libs/printf/ft_puthexa_nbr.c
        libs/printf/ft_putnbr_n.c
        libs/printf/ft_putstr.c
        # GET_NEXT_LINE
        libs/get_next_line/get_next_line.c
        libs/get_next_line/get_next_line_utils.c
        # SO_LONG
#        srcs/so_long.c
        srcs/ft_free_errors.c
        srcs/get_map_and_validate_items.c
        srcs/init_structs.c
        srcs/validations_map.c
        srcs/print_functions.c
        srcs/flood_fill.c
        srcs/graphics.c
        srcs/moves_game.c
        # MINILIB_LINUX
        libs/minilibx-linux/mlx_int_wait_first_expose.c
        libs/minilibx-linux/mlx_get_data_addr.c
        libs/minilibx-linux/mlx_screen_size.c
        libs/minilibx-linux/mlx_int_str_to_wordtab.c
        libs/minilibx-linux/mlx_int_set_win_event_mask.c
        libs/minilibx-linux/mlx_clear_window.c
        libs/minilibx-linux/mlx_int_get_visual.c
        libs/minilibx-linux/mlx_destroy_image.c
        libs/minilibx-linux/mlx_string_put.c
#        libs/minilibx-linux/mlx_lib_xpm.c
        libs/minilibx-linux/mlx_ext_randr.c
        libs/minilibx-linux/mlx_rgb.c
        libs/minilibx-linux/mlx_pixel_put.c
        libs/minilibx-linux/mlx_new_window.c
        libs/minilibx-linux/mlx_flush_event.c
        libs/minilibx-linux/mlx_loop_hook.c
        libs/minilibx-linux/mlx_hook.c
        libs/minilibx-linux/mlx_new_image.c
        libs/minilibx-linux/mlx_int_do_nothing.c
        libs/minilibx-linux/mlx_destroy_window.c
        libs/minilibx-linux/mlx_set_font.c
        libs/minilibx-linux/mlx_put_image_to_window.c
        libs/minilibx-linux/mlx_mouse.c
        libs/minilibx-linux/mlx_loop.c
        libs/minilibx-linux/mlx_int_anti_resize_win.c
        libs/minilibx-linux/mlx_mouse_hook.c
        libs/minilibx-linux/mlx_key_hook.c
        libs/minilibx-linux/mlx_destroy_display.c
        libs/minilibx-linux/mlx_get_color_value.c
        libs/minilibx-linux/mlx_init.c
        libs/minilibx-linux/mlx_xpm.c
        libs/minilibx-linux/mlx_int_param_event.c
        libs/minilibx-linux/mlx_expose_hook.c
        srcs/free_game.c
)

# Asegurarse de que el target so_long_42 dependa de libmlx.a
add_dependencies(so_long_42 libmlx)

# Enlazar el ejecutable con libmlx.a y las bibliotecas X11 y Xext
target_link_libraries(so_long_42
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/minilibx-linux/libmlx_Linux.a
        X11
        Xext
        Xpm
        Xrandr
)
