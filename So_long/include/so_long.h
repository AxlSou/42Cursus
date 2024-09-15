/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:00:32 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 17:08:22 by asoubiel         ###   ########.fr       */
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

typedef struct s_collectibles
{
	mlx_image_t				*collectible_img;
	int						x;
	int						y;
	struct s_collectibles	*next;
}							t_collectibles;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_pos[2];
	int				exit_pos[2];
	int				collectibles_count;
	int				moves;
	t_player_img	*player_img;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	t_collectibles	*collectibles;
	mlx_image_t		*floor1;
	mlx_image_t		*floor2;
}					t_game;

void	error(char *str);
void	error_mlx(void);
void	init(t_game *game);
void	load_img(t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);
void	render_ground(t_game *game);
void	render_player(t_game *game);
void	render_walls(t_game *game);
void	render_collectibles(t_game *game);
void	render_exit(t_game *game);
void	collect_to_window(t_game *game, int x, int y);
void	load_collectible(t_game *game, t_collectibles *collectibles);
void	collect(t_game *game, int x, int y);
void	collect_lst_clear(t_game *game, t_collectibles **lst);
int		move_checks(t_game *game, int x, int y);
void	remove_player_img(t_game *game);
void	exit_game(t_game *game);

// Map validation
void	init_pos_count(t_game *game);
void	init_exit_count(t_game *game);
void	is_map_rectangular(t_game *game);
void	map_has_collectibles(t_game *game);
void	is_map_closed(t_game *game);

#endif
