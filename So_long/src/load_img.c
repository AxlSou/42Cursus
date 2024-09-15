/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:21:43 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 17:03:54 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_player(t_game *game)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/player/Player.png");
	if (!player)
		error_mlx();
	game->player_img->player_d = mlx_texture_to_image(game->mlx, player);
	if (!game->player_img->player_d)
		error_mlx();
}

static void	load_img_floor(t_game *game)
{
	mlx_texture_t	*floor1;
	mlx_texture_t	*floor2;

	floor1 = mlx_load_png("./assets/floor/Grass1.png");
	if (!floor1)
		error_mlx();
	floor2 = mlx_load_png("./assets/floor/Grass2.png");
	if (!floor2)
		error_mlx();
	game->floor1 = mlx_texture_to_image(game->mlx, floor1);
	if (!game->floor1)
		error_mlx();
	game->floor2 = mlx_texture_to_image(game->mlx, floor2);
	if (!game->floor2)
		error_mlx();
}

static void	load_wall(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/Tree.png");
	if (!wall)
		error_mlx();
	game->wall = mlx_texture_to_image(game->mlx, wall);
	if (!game->wall)
		error_mlx();
}

void	load_collectible(t_game *game, t_collectibles *collectibles)
{
	mlx_texture_t	*collect;

	collect = mlx_load_png("./assets/Chest.png");
	if (!collect)
		error_mlx();
	collectibles->collectible_img = mlx_texture_to_image(game->mlx,
			collect);
	if (!collectibles->collectible_img)
		error_mlx();
}

void	load_img(t_game *game)
{
	mlx_texture_t	*exit;

	load_img_floor(game);
	load_player(game);
	load_wall(game);
	exit = mlx_load_png("./assets/Exit.png");
	if (!exit)
		error_mlx();
	game->exit = mlx_texture_to_image(game->mlx, exit);
	if (!game->exit)
		error_mlx();
}
