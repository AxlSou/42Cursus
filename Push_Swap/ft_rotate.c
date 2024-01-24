/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:45:59 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/23 23:50:35 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;

    tmp = (*lst)->next; 
    ft_lstadd_back(lst, ft_lstnew(ft_strdup((*lst)->content)));
    ft_lstdelone(*lst, free);
    *lst = tmp;
}

void    ft_ra(t_list **lst)
{
    ft_rotate(lst);
    ft_printf("ra");
}

void    ft_rb(t_list **lst)
{
    ft_rotate(lst);
    ft_printf("rb");
}

void    ft_rr(t_list **lst_a, t_list **lst_b)
{
    ft_rotate(lst_a);
    ft_rotate(lst_b);
    ft_printf("rr");
}