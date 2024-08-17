/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:26:08 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/17 21:23:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!game->mlx)
		error();

	load_img(game);
}
