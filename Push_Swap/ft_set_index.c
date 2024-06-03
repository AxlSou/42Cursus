/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:52:52 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/03 22:43:16 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(l_list **stack, int index, int missing_index)
{
    l_list  *current;
    int     num;

    current = *stack;
    num = ft_max_number(stack) + 1;
    while (current && missing_index)
    {
        missing_index = 0;
        if (current->content < num && !current->index)
        {
            num = current->content;
            missing_index = 1;
        }
        current = current->next;
    }
    if (missing_index == 0)
        return ;
    while (current->content != num)
        current = current->next;
    current->index = index;
    return ft_set_index(stack, index + 1, missing_index);
}
