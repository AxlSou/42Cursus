/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:02 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 20:27:38 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*current;

	current = *stack_a;
	size = ft_sizelst(stack_a);
	while (current)
	{
		if (current->index < size / 2)
			ft_pb(stack_a, stack_b);
		current = current->next;
	}
	current = *stack_a;
	while (current)
	{
		if (current->index < size - 3)
			ft_pb(stack_a, stack_b);
		current = current->next;
	}
}
