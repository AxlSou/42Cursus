/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:56:05 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/16 10:07:19 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost(t_stack **stack_a, t_stack **stack_b,
						int size_a, int size_b)
{
	t_stack	*current;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current = *stack_b;
	while (current)
	{
		if (current->position <= size_b / 2
			&& current->target_pos <= size_a / 2)
			current->cost = current->position + current->target_pos;
		else if (current->position > size_b / 2
			&& current->target_pos <= size_a / 2)
			current->cost = (size_b - current->position) + current->target_pos;
		else if (current->position <= size_b / 2
			&& current->target_pos > size_a / 2)
			current->cost = current->position + (size_a - current->target_pos);
		else
			current->cost = (size_b - current->position)
				+ (size_a - current->target_pos);
		current = current->next;
	}
}
