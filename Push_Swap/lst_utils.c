/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:24:22 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 19:55:41 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newlst(int content)
{
	t_stack	*new_n;

	new_n = (t_stack *)malloc(sizeof(t_stack));
	if (!new_n)
		return (NULL);
	new_n->content = content;
    new_n->index = 0;
    new_n->position = 0;
    new_n->cost = 0;
	new_n->next = NULL;
	return (new_n);
}

void ft_add_back_lst(t_stack **lst, t_stack *new_n)
{
    t_stack	*current;

    if (!lst || !new_n)
        return ;
    if (!*lst)
        *lst = new_n;
    current = *lst;
    while (current->next)
        current = current->next;
    current->next = new_n;
}

void	ft_add_front_lst(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack   *ft_lastnode(t_stack *lst)
{
    t_stack	*current;

    current = lst;
    if (!lst)
        return (NULL);
    while (current->next)
        current = current->next;
    return (current);
}

void   ft_clearlst(t_stack **lst, void (*del)(void *))
{
    t_stack	*current;
    t_stack	*tmp;

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