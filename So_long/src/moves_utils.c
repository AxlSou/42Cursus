/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:22:43 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 15:39:41 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_checks(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (-1);
	else if (game->map[y][x] == 'C')
		collect(game, x, y);
	else if (game->map[y][x] == 'E')
	{
		if (game->collectibles_count == 0)
		{
			mlx_delete_image(game->mlx, game->exit);
			exit_game(game);
		}
	}
	return (0);
}
