/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:00:32 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/14 18:44:41 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/Libft/includes/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player_img
{
	mlx_image_t		*player_d;
	mlx_image_t		*player_u;
	mlx_image_t		*player_l;
	mlx_image_t		*player_r;
}					t_player_img;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_pos[2];
	int				exit_pos[2];
	int				collectibles;
	int				moves;
	t_player_img	*player_img;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*collectible;
	mlx_image_t		*floor1;
	mlx_image_t		*floor2;
}					t_game;

void	error(void);
void	init(t_game *game);
void	load_img(t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

#endif
