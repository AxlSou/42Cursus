/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:40:25 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 20:27:19 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*current;
	t_stack	*tmp;

	current = *stack_src;
	ft_add_front_lst(stack_dst, ft_newlst(current->content));
	tmp = current;
	*stack_src = (*stack_src)->next;
	current = *stack_src;
	free(tmp);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
