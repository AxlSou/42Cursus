/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:40:25 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/01 14:46:44 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(l_list **stack_src, l_list **stack_dst)
{
	l_list	*current;
	l_list	*tmp;

	current = *stack_src;
	ft_add_front_lst(stack_dst, ft_newlst(current->content));
	tmp = current;
	*stack_src = (*stack_src)->next;
	current = *stack_src;
	free(tmp);
}

void	ft_pa(l_list **stack_a, l_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(l_list **stack_b, l_list **stack_a)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
