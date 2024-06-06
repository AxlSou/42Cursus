/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_target_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:12:26 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/06 20:30:31 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		target;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_b = *stack_b;
	while (current_b)
	{
		current_a = *stack_a;
		target = -1;
		while (current_a)
		{
			if (current_a->index - current_b->index < target || target == -1)
			{
				target = current_a->index - current_b->index;
				current_b->target_pos = current_a->position;
			}
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}
