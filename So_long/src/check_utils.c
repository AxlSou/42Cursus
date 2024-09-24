/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:55:53 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 17:10:02 by asoubiel         ###   ########.fr       */
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
		error("Player position error");
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
		error("Exit position error");
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
			error("Map is not rectangular");
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
		error("Map has no collectibles");
}

void	is_map_closed(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y++])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 || y == game->map_height || x == 0
				|| x == game->map_width - 1)
			{
				if (game->map[y][x] != '1')
					error("Map is not closed");
			}
			else
			{
				if (game->map[y][x] != '1' && game->map[y][x] != '0'
					&& game->map[y][x] != 'P' && game->map[y][x] != 'C'
					&& game->map[y][x] != 'E')
					error("Map is not closed");
			}
			x++;
		}
	}
}