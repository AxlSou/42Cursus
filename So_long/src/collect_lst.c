/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:30:13 by asoubiel          #+#    #+#             */
/*   Updated: 2024/09/30 19:48:18 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_collectibles	*collect_lst_new(int x, int y)
{
	t_collectibles	*new;

	new = malloc(sizeof(t_collectibles));
	if (!new)
		return (NULL);
	new->collectible_img = NULL;
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

t_collectibles	*collect_lst_last(t_collectibles *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	collect_lst_add_back(t_collectibles **lst, t_collectibles *new)
{
	t_collectibles	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = collect_lst_last(*lst);
	last->next = new;
}

void	collect_lst_clear(t_game *game, t_collectibles **lst)
{
	t_collectibles	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->collectible_img)
			mlx_delete_image(game->mlx, (*lst)->collectible_img);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
