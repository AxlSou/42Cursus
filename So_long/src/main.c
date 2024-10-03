/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:13:50 by asoubiel          #+#    #+#             */
/*   Updated: 2024/10/01 19:08:17 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	ext_error(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->player_img = (t_player_img *)malloc(sizeof(t_player_img));
	if (game->player_img == NULL)
		return (free(game), 1);
	if (read_map(game, argv[1]) < 0)
		return (parser_error(game, "Error: Read map error"), EXIT_FAILURE);
	get_items(game);
	flood_fill(game, game->player_pos[0], game->player_pos[1]);
	map_checks(game, game->collectibles);
	init(game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (EXIT_SUCCESS);
}
