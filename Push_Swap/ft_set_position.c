/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:36:29 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/06 20:30:16 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		i;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current = *stack_a;
	i = 0;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
	current = *stack_b;
	i = 0;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}
