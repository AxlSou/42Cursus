/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:26 by asoubiel          #+#    #+#             */
/*   Updated: 2023/12/01 22:15:44 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!*lst)
		*lst = NULL;
	else
	{
		current = *lst;
		next = current->next;
		del(current->content);
		while (next)
		{
			current = next;
			del(current->content);
			next = current->next;
			free(current);
		}
		free(*lst);
		*lst = NULL;
	}
}
