/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:13:50 by asoubiel          #+#    #+#             */
/*   Updated: 2024/08/22 20:06:23 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	mlx_t	*mlx;

	game = (t_game *)malloc(sizeof(t_game));
	mlx = NULL;
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// {
	// 	printf("Usage: %s <map>\n", argv[0]);
	// 	return (EXIT_FAILURE);
	// }
	// else
	// {
	// 	init(game);
	// }
	init(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
