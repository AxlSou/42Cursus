/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:41:39 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/23 23:41:54 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_list **lst)
{
    void *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;

    tmp = (*lst)->next->content;
    (*lst)->next->content = (*lst)->content;
    (*lst)->content = tmp;
}

void    ft_sa(t_list **lst)
{
    ft_swap(lst);
    ft_printf("sa");
}

void    ft_sb(t_list **lst)
{
    ft_swap(lst);
    ft_printf("sb");
}

void    ft_ss(t_list **lst_a, t_list **lst_b)
{
    ft_swap(lst_a);
    ft_swap(lst_b);
    ft_printf("ss");
}