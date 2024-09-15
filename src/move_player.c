/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:59:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 17:03:07 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	remove_player_img(t_game *game)
{
	if (game->player_img->player_d)
	{
		mlx_delete_image(game->mlx, game->player_img->player_d);
		game->player_img->player_d = NULL;
	}
	else if (game->player_img->player_u)
	{
		mlx_delete_image(game->mlx, game->player_img->player_u);
		game->player_img->player_u = NULL;
	}
	else if (game->player_img->player_l)
	{
		mlx_delete_image(game->mlx, game->player_img->player_l);
		game->player_img->player_l = NULL;
	}
	else if (game->player_img->player_r)
	{
		mlx_delete_image(game->mlx, game->player_img->player_r);
		game->player_img->player_r = NULL;
	}
}

void	move_player_up(t_game *game)
{
	int		x;
	int		y;

	x = game->player_pos[0];
	y = game->player_pos[1];
	if (!game->player_img->player_u)
	{
		remove_player_img(game);
		game->player_img->player_u = mlx_texture_to_image(game->mlx,
				mlx_load_png("./assets/player/PlayerUp.png"));
		if (!game->player_img->player_u)
			error_mlx();
		if (mlx_image_to_window(game->mlx,
				game->player_img->player_u, x * 64, y * 64) < 0)
			error_mlx();
	}
	if (move_checks(game, x, y - 1) < 0)
		return ;
	game->player_img->player_u->instances->y -= 64;
	game->player_pos[1] -= 1;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_player_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos[0];
	y = game->player_pos[1];
	if (!game->player_img->player_d)
	{
		remove_player_img(game);
		game->player_img->player_d = mlx_texture_to_image(game->mlx,
				mlx_load_png("./assets/player/Player.png"));
		if (!game->player_img->player_d)
			error_mlx();
		if (mlx_image_to_window(game->mlx,
				game->player_img->player_d, x * 64, y * 64) < 0)
			error_mlx();
	}
	if (move_checks(game, x, y + 1) < 0)
		return ;
	game->player_img->player_d->instances->y += 64;
	game->player_pos[1] += 1;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_player_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos[0];
	y = game->player_pos[1];
	if (!game->player_img->player_l)
	{
		remove_player_img(game);
		game->player_img->player_l = mlx_texture_to_image(game->mlx,
				mlx_load_png("./assets/player/PlayerL.png"));
		if (!game->player_img->player_l)
			error_mlx();
		if (mlx_image_to_window(game->mlx,
				game->player_img->player_l, x * 64, y * 64) < 0)
			error_mlx();
	}
	if (move_checks(game, x - 1, y) < 0)
		return ;
	game->player_img->player_l->instances->x -= 64;
	game->player_pos[0] -= 1;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_player_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos[0];
	y = game->player_pos[1];
	if (!game->player_img->player_r)
	{
		remove_player_img(game);
		game->player_img->player_r = mlx_texture_to_image(game->mlx,
				mlx_load_png("./assets/player/PlayerR.png"));
		if (!game->player_img->player_r)
			error_mlx();
		if (mlx_image_to_window(game->mlx,
				game->player_img->player_r, x * 64, y * 64) < 0)
			error_mlx();
	}
	if (move_checks(game, x + 1, y) < 0)
		return ;
	game->player_img->player_r->instances->x += 64;
	game->player_pos[0] += 1;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}
