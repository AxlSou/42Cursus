/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:52:16 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/30 19:08:00 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	is_exit_reachable(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				if (game->map[y + 1][x] == 'F' || game->map[y - 1][x] == 'F' ||
					game->map[y][x + 1] == 'F' || game->map[y][x - 1] == 'F')
				{
					return ;
				}
				else
					parser_error(game, "Exit unreachable");
			}
			x++;
		}
		y++;
	}
}

static void	is_collectible_reachable(t_game *game, t_collectibles *collectibles)
{
	int	x;
	int	y;

	while (collectibles)
	{
		x = collectibles->x;
		y = collectibles->y;
		if (game->map[y + 1][x] == 'F' || game->map[y - 1][x] == 'F' ||
			game->map[y][x + 1] == 'F' || game->map[y][x - 1] == 'F')
		{
			collectibles = collectibles->next;
		}
		else
			parser_error(game, "Collectible unreachable");
	}
}

void	map_checks(t_game *game, t_collectibles *collectibles)
{
	init_pos_count(game);
	init_exit_count(game);
	is_map_rectangular(game);
	is_map_closed(game);
	map_has_collectibles(game);
	is_exit_reachable(game);
	is_collectible_reachable(game, collectibles);
}
