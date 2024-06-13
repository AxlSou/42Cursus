/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/13 20:58:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_number(t_stack **lst)
{
	int		num;
	t_stack	*current;
	int		max_index;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	num = current->content;
	max_index = current->index;
	while (current)
	{
		if (current->content > num)
		{
			num = current->content;
			max_index = current->index;
		}
		current = current->next;
	}
	return (max_index);
}

int	ft_min_cost(t_stack **lst)
{
	int		cost;
	t_stack	*current;
	int		min_index;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	cost = current->cost;
	min_index = current->index;
	while (current)
	{
		if (current->content < cost)
		{
			cost = current->content;
			min_index = current->index;
		}
		current = current->next;
	}
	return (min_index);
}
