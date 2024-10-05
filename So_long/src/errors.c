/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:41:18 by asoubiel          #+#    #+#             */
/*   Updated: 2024/10/01 19:44:04 by asoubiel         ###   ########.fr       */
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

void	error_mlx(t_game *game)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit_game(game);
}

void	parser_error(t_game *game, char *str)
{
	ft_printf("Error:\n");
	ft_printf("%s\n", str);
	free_map(game);
	if (game->collectibles)
		collect_lst_clear(game, &game->collectibles);
	if (game->player_img)
		free(game->player_img);
	if (game)
		free(game);
	exit(1);
}

void	ext_error(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
		&& str[len - 4] == '.')
		return ;
	else
	{
		ft_printf("Error: Invalid extension\n");
		exit(1);
	}
}

void	error(t_game *game, char *str)
{
	ft_printf("Error:\n");
	ft_printf("%s\n", str);
	exit_game(game);
}
