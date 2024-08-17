/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:21:43 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/17 20:21:01 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_img(t_game *game)
{
	game->floor1 = mlx_load_png("./assets/Grass1.png");
	if (!game->floor1)
		error();
	game->floor2 = mlx_load_png("./assets/Grass2.png");
	if (!game->floor2)
		error();
}
