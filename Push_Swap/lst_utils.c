/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:24:22 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/01 15:26:45 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

l_list	*ft_newlst(int content)
{
	l_list	*new_n;

	new_n = (l_list *)malloc(sizeof(l_list));
	if (!new_n)
		return (NULL);
	new_n->content = content;
    new_n->index = 0;
    new_n->position = 0;
    new_n->cost = 0;
	new_n->next = NULL;
	return (new_n);
}

void ft_add_back_lst(l_list **lst, l_list *new_n)
{
    l_list	*current;

    if (!lst || !new_n)
        return ;
    if (!*lst)
        *lst = new_n;
    current = *lst;
    while (current->next)
        current = current->next;
    current->next = new_n;
}

void	ft_add_front_lst(l_list **lst, l_list *new)
{
	new->next = *lst;
	*lst = new;
}

l_list   *ft_lastnode(l_list *lst)
{
    l_list	*current;

    current = lst;
    if (!lst)
        return (NULL);
    while (current->next)
        current = current->next;
    return (current);
}

void   ft_clearlst(l_list **lst, void (*del)(void *))
{
    l_list	*current;
    l_list	*tmp;

    if (!lst || !*lst)
        return ;
    current = *lst;
    while (current)
    {
        tmp = current->next;
        del(current);
        current = tmp;
    }
    *lst = NULL;
}