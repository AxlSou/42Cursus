/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:08 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 17:02:25 by asoubiel         ###   ########.fr       */
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
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_game(game);
}

void	init(t_game *game)
{
	game->mlx = mlx_init(game->map_width * 64,
			game->map_height * 64, "Test", true);
	if (!game->mlx)
		error_mlx();
	load_img(game);
	game->player_img->player_u = NULL;
	game->player_img->player_r = NULL;
	game->player_img->player_l = NULL;
	game->collectibles = 0;
	game->moves = 0;
	render_ground(game);
	render_walls(game);
	render_player(game);
	render_collectibles(game);
	render_exit(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
}
