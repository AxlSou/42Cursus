/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:13:50 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/24 21:02:50 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Usage: %s <map>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		game = (t_game *)malloc(sizeof(t_game));
		game->player_img = (t_player_img *)malloc(sizeof(t_player_img));
		if (read_map(game, argv[1]) < 0)
			return (EXIT_FAILURE);
		get_items(game);
		flood_fill(game, game->player_pos[0], game->player_pos[1]);
		map_checks(game, game->collectibles);
		init(game);
		mlx_loop(game->mlx);
		exit_game(game);
	}
	return (EXIT_SUCCESS);
}
