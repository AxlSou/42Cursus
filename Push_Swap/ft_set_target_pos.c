/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:12:26 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/16 10:12:41 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Assigns target positions in stack_a for elements in stack_b.
 * This function determines where each element of stack_b should be placed
 * in stack_a to maintain or achieve sorted order. It iterates through stack_b,
 * comparing each element with those in stack_a to find the appropriate
 * target position based on three criteria:
 * 1. If it fits between two elements in stack_a.
 * 2. If it's less than the minimum or greater than the maximum in stack_a.
 * 3. If it should be placed at the start of stack_a.
 */

void	ft_set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_b = *stack_b;
	while (current_b)
	{
		current_a = *stack_a;
		while (current_a->next)
		{
			if (current_b->index > current_a->index
				&& current_b->index < current_a->next->index)
				current_b->target_pos = current_a->next->position;
			current_a = current_a->next;
		}
		if (current_b->content < ft_min_number(stack_a)
			|| current_b->content > ft_max_number(stack_a))
			current_b->target_pos = ft_get_position(stack_a,
					ft_min_number(stack_a));
		else if (current_b->content < (*stack_a)->content
			&& current_b->content > ft_lastnode(*stack_a)->content)
			current_b->target_pos = 0;
		current_b = current_b->next;
	}
}
