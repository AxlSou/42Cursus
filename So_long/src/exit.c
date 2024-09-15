/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:20:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 15:32:40 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_game *game)
{
	remove_player_img(game);
	collect_lst_clear(game, &game->collectibles);
	free(game->player_img);
	mlx_terminate(game->mlx);
	free(game);
	exit(0);
}
