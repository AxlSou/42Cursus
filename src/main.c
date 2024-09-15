/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:13:50 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/15 16:51:43 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_map_size(t_game *game, char *map)
{
	char	*line;
	int		fd;

	game->map_height = 0;
	game->map_width = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		game->map_height++;
		if (game->map_width < (int)ft_strlen(line) - 1)
			game->map_width = ft_strlen(line) - 1;
		free(line);
		line = get_next_line(fd);
	}
}

static int	read_map(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	get_map_size(game, map);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (-1);
	game->map[game->map_height] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!game->map[i])
			return (-1);
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (close(fd));
}

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
		init(game);
		mlx_loop(game->mlx);
		exit_game(game);
	}
	return (EXIT_SUCCESS);
}
