/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:56:05 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/06 20:29:36 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost(t_stack **stack_b)
{
	t_stack	*current;

	if (!stack_b || !*stack_b)
		return ;
	current = *stack_b;
	while (current)
	{
		current->cost = current->position + current->target_pos;
		current = current->next;
	}
}
