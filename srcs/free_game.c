#include "../includes/so_long.h"

void    free_game_complete(t_game *game)
{
	free_images_xpm(game);
    free_map_copy(game->map, NULL);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game);
    exit(0);
}

void    free_images_xpm(t_game *game)
{
    if (game->wall.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
    if (game->floor.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
    if (game->coins.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
    if (game->exit_open.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
    if (game->exit_closed.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
    if (game->player_front.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
    if (game->player_left.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
    if (game->player_right.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
    if (game->player_back.xpm_ptr)
        mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
}

/*
void	free_game_ptr(t_game *game, char* message)
{
	if (message)
		ft_printf(message);
	if (game->win_ptr)
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
	}
	if (game->map)
		free_map_copy(game->map, message);
}
*/