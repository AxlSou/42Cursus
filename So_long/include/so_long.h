/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:00:32 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/17 21:35:23 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../libs/Libft/includes/libft.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"
#define WIDTH 800
#define HEIGHT 600

typedef struct s_game
{
	mlx_t *mlx;
	char **map;
	int map_width;
	int map_height;
	int player_pos[2];
	int exit_pos[2];
	int collectibles;
	int moves;
	mlx_texture_t *player;
	mlx_texture_t *wall;
	mlx_texture_t *exit;
	mlx_texture_t *collectible;
	mlx_texture_t *floor1;
	mlx_texture_t *floor2;
} t_game;

void error(void);
void init(t_game *game);
void load_img(t_game *game);

#endif
