/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:55:53 by asoubiel          #+#    #+#             */
/*   Updated: 2024/10/01 18:44:26 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_pos_count(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		parser_error(game, "Player position error");
}

void	init_exit_count(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		parser_error(game, "Exit position error");
}

void	is_map_rectangular(t_game *game)
{
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != len)
			parser_error(game, "Map is not rectangular");
		y++;
	}
}

void	map_has_collectibles(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		parser_error(game, "Map has no collectibles");
}

void	is_map_closed(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (x < game->map_width)
		{
			if (y == 0 || y == game->map_height || x == 0
				|| x == game->map_width - 1)
			{
				if (game->map[y][x] != '1')
					parser_error(game, "Map is not closed");
			}
			else
			{
				if (game->map[y][x] != '1' && game->map[y][x] != '0'
					&& game->map[y][x] != 'P' && game->map[y][x] != 'C'
					&& game->map[y][x] != 'E' && game->map[y][x] != 'F')
					parser_error(game, "Map is not closed");
			}
			x++;
		}
	}
}
