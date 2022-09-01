#include "so_long.h"

void	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

void    ft_put_exit(t_game *game)
{
    game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/player/Dawn_left2.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
}

void    ft_put_player(t_game *game)
{
    game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/player/Dawn_down1.xpm", &game->pxl, &game->pxl);
	game->pl_x = game->x;
	game->pl_y = game->y;
	mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
}

void    ft_put_collect(t_game *game)
{
    game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/player/Dawn_right2.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
	game->collect++;
}

void    ft_put_floor(t_game *game)
{
    game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/Grass.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
}

void    ft_put_wall(t_game *game)
{
    game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/Tree.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
}

void	ft_fill_floor(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			ft_put_floor(game);
			game->x++;
		}
		game->y++;
	}
}

void	ft_window_file(t_game *game)
{
	ft_fill_floor(game);
	game->y = 0;
	game->collect = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == '1')
				ft_put_wall(game);
			if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	ft_printf("Movements: %d\n", game->pl_mov);
}