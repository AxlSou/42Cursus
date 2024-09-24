/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:20:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/24 21:17:23 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	exit_game(t_game *game)
{
	remove_player_img(game);
	collect_lst_clear(game, &game->collectibles);
	if (game->player_img)
		free(game->player_img);
	mlx_terminate(game->mlx);
	free_map(game);
	if (game)
		free(game);
	exit(0);
}
