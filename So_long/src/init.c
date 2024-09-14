/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:08 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/14 22:15:53 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_up(game);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_down(game);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_left(game);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player_right(game);
}

static void	render_ground(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (((x * 64) + (y * 64)) % 128 == 0)
			{
				if (mlx_image_to_window(game->mlx, game->floor1,
						x * 64, y * 64) < 0)
					error();
			}
			else
			{
				if (mlx_image_to_window(game->mlx, game->floor2,
						x * 64, y * 64) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}

static void	render_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->wall,
						x * 64, y * 64) < 0)
					error();
			}
			x++;
		}
		y++;
	}
}

void	init(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 64,
			game->map_height * 64, "Test", true);
	if (!game->mlx)
		error();
	load_img(game);
	game->player_img->player_u = NULL;
	game->player_img->player_r = NULL;
	game->player_img->player_l = NULL;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	game->collectibles = 0;
	game->moves = 0;
	render_ground(game);
	render_walls(game);
	if (mlx_image_to_window(game->mlx, game->player_img->player_d, 0, 0) < 0)
		error();
	mlx_key_hook(game->mlx, &my_keyhook, game);
}
