/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:40:25 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/23 23:49:30 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push(t_list **stack_src, t_list **stack_dst)
{
    t_list *current;
    t_list *tmp;

    current = *stack_src;
    ft_lstadd_front(stack_dst, ft_lstnew(ft_strdup(current->content)));
    tmp = current;
    *stack_src = (*stack_src)->next;
    current = *stack_src;
    ft_lstdelone(tmp, free);
}

void    ft_pa(t_list **stack_a, t_list **stack_b)
{
    ft_push(stack_b, stack_a);
    ft_printf("pa\n");
}

void    ft_pb(t_list **stack_b, t_list **stack_a)
{
    ft_push(stack_a, stack_b);
    ft_printf("pb\n");
}