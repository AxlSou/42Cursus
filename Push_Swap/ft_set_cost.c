/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:56:05 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/11 21:17:25 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost(t_stack **stack_b)
{
	t_stack	*current;
	int		size;

	if (!stack_b || !*stack_b)
		return ;
	size = ft_sizelst(stack_b);
	current = *stack_b;
	while (current)
	{
		if (current->position <= size / 2)
			current->cost = current->position + current->target_pos;
		else
			current->cost = (size - current->position) + current->target_pos;
		current = current->next;
	}
}
