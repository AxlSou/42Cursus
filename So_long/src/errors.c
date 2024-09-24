/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:41:18 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/24 20:08:59 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (game->map[y][x] == '1' || game->map[y][x] == 'C' ||
			game->map[y][x] == 'F' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] != 'P')
		game->map[y][x] = 'F';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	error_mlx(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	error(t_game *game, char *str)
{
	ft_printf("Error:\n");
	ft_printf("%s\n", str);
	exit_game(game);
}
