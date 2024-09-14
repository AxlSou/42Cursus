/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:13:50 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/14 12:39:20 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->player_img = (t_player_img *)malloc(sizeof(t_player_img));
	if (argc != 2)
	{
		printf("Usage: %s <map>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	else
	{
		init(game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
	return (EXIT_SUCCESS);
}
