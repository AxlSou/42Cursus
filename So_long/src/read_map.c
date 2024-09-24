/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:43:18 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/24 21:22:07 by asoubiel         ###   ########.fr       */
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

int	read_map(t_game *game, char *map)
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
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (close(fd));
}
