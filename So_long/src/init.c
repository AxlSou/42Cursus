/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:08 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/14 13:02:09 by asoubiel         ###   ########.fr       */
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

void	init(t_game *game)
{
	int			x;
	int			y;

	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game->mlx)
		error();
	load_img(game);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if ((x + y) % 32 == 0)
			{
				if (mlx_image_to_window(game->mlx, game->floor1, x, y) < 0)
					error();
			}
			else
			{
				if (mlx_image_to_window(game->mlx, game->floor2, x, y) < 0)
					error();
			}
			y += 16;
		}
		x += 16;
	}
	game->player_img->player_u = NULL;
	game->player_img->player_r = NULL;
	game->player_img->player_l = NULL;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	if (mlx_image_to_window(game->mlx, game->player_img->player_d, 0, 0) < 0)
		error();
	mlx_key_hook(game->mlx, &my_keyhook, game);
}
