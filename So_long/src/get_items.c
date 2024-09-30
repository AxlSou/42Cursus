/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:03:16 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/30 20:10:49 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_player_pos(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	y = 0;
	game->player_pos[0] = -1;
	game->player_pos[1] = -1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->player_pos[0] = x;
				game->player_pos[1] = y;
			}
			x++;
		}
		y++;
	}
	if (game->player_pos[0] == -1 || game->player_pos[1] == -1)
		parser_error(game, "Player position error");
}

static void	get_collectibles(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				collect_lst_add_back(&game->collectibles,
					collect_lst_new(x, y));
				game->collectibles_count++;
			}
			x++;
		}
		y++;
	}
}

void	get_items(t_game *game)
{
	game->collectibles = NULL;
	game->collectibles_count = 0;
	get_player_pos(game);
	get_collectibles(game);
}
