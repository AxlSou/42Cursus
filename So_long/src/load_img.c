/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:21:43 by asoubiel          #+#    #+#             */
/*   Updated: 2024/10/01 19:27:21 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_player(t_game *game)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./textures/player/Player.png");
	if (!player)
		error_mlx(game);
	game->player_img->player_d = mlx_texture_to_image(game->mlx, player);
	mlx_delete_texture(player);
	if (!game->player_img->player_d)
		error_mlx(game);
}

static void	load_img_floor(t_game *game)
{
	mlx_texture_t	*floor1;
	mlx_texture_t	*floor2;

	floor1 = mlx_load_png("./textures/floor/Grass1.png");
	if (!floor1)
		error_mlx(game);
	floor2 = mlx_load_png("./textures/floor/Grass2.png");
	if (!floor2)
		error_mlx(game);
	game->floor1 = mlx_texture_to_image(game->mlx, floor1);
	if (!game->floor1)
		error_mlx(game);
	game->floor2 = mlx_texture_to_image(game->mlx, floor2);
	mlx_delete_texture(floor1);
	mlx_delete_texture(floor2);
	if (!game->floor2)
		error_mlx(game);
}

static void	load_wall(t_game *game)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./textures/Tree.png");
	if (!wall)
		error_mlx(game);
	game->wall = mlx_texture_to_image(game->mlx, wall);
	mlx_delete_texture(wall);
	if (!game->wall)
		error_mlx(game);
}

void	load_collectible(t_game *game, t_collectibles *collectibles)
{
	mlx_texture_t	*collect;

	collect = mlx_load_png("./textures/Chest.png");
	if (!collect)
		error_mlx(game);
	collectibles->collectible_img = mlx_texture_to_image(game->mlx,
			collect);
	mlx_delete_texture(collect);
	if (!collectibles->collectible_img)
		error_mlx(game);
}

void	load_img(t_game *game)
{
	mlx_texture_t	*exit;

	load_img_floor(game);
	load_player(game);
	load_wall(game);
	exit = mlx_load_png("./textures/Exit.png");
	if (!exit)
		error_mlx(game);
	game->exit = mlx_texture_to_image(game->mlx, exit);
	mlx_delete_texture(exit);
	if (!game->exit)
		error_mlx(game);
}
