/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:12 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 12:19:02 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect(t_game *game, int x, int y)
{
	t_collectibles	*collect;
	t_collectibles	*prev;

	prev = NULL;
	collect = game->collectibles;
	while (collect)
	{
		if (collect->x == x && collect->y == y)
		{
			mlx_delete_image(game->mlx, collect->collectible_img);
			game->map[y][x] = '0';
			if (prev)
				prev->next = collect->next;
			else
				game->collectibles = collect->next;
			free(collect);
			game->collectibles_count--;
			return ;
		}
		prev = collect;
		collect = collect->next;
	}
}
