/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:08 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/22 20:10:51 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*img1;
	mlx_image_t	*img2;

	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game->mlx)
		error();
	load_img(game);
	img1 = mlx_texture_to_image(game->mlx, game->floor1);
	if (!img1)
		error();
	img2 = mlx_texture_to_image(game->mlx, game->floor2);
	if (!img2)
		error();
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if ((x + y) % 32 == 0)
			{
				if (mlx_image_to_window(game->mlx, img1, x, y) < 0)
					error();
			}
			else
			{
				if (mlx_image_to_window(game->mlx, img2, x, y) < 0)
					error();
			}
			y += 16;
		}
		x += 16;
	}
}
