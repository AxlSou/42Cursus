/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:24:35 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/24 21:08:03 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_ground(t_game *game)
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
					error_mlx();
			}
			else
			{
				if (mlx_image_to_window(game->mlx, game->floor2,
						x * 64, y * 64) < 0)
					error_mlx();
			}
			x++;
		}
		y++;
	}
}

void	render_walls(t_game *game)
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
					error_mlx();
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player_pos[0];
	y = game->player_pos[1];
	if (mlx_image_to_window(game->mlx, game->player_img->player_d,
			x * 64, y * 64) < 0)
		error_mlx();
}

void	render_collectibles(t_game *game)
{
	t_collectibles	*collect;

	collect = game->collectibles;
	while (collect)
	{
		load_collectible(game, collect);
		if (mlx_image_to_window(game->mlx, collect->collectible_img,
				collect->x * 64, collect->y * 64) < 0)
			error_mlx();
		collect->collectible_img->instances->x += 8;
		collect->collectible_img->instances->y += 8;
		collect = collect->next;
	}
}

void	render_exit(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->exit,
						x * 64, y * 64) < 0)
					error_mlx();
				game->exit_pos[0] = x;
				game->exit_pos[1] = y;
			}
			x++;
		}
		y++;
	}
	game->exit->instances->x += 8;
	game->exit->instances->y += 8;
}
