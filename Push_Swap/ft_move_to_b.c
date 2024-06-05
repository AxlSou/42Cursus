/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:15:02 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/05 20:29:54 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		i;

	i = 0;
	size = ft_sizelst(stack_a);
	while (ft_sizelst(stack_a) > 3 && i != size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
	while (ft_sizelst(stack_a) > 3)
	{
		if ((*stack_a)->index <= size - 3)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
}
