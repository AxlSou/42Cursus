/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/14 19:33:51 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_number(t_stack **lst)
{
	int		num;
	t_stack	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	num = current->content;
	while (current)
	{
		if (current->content > num)
			num = current->content;
		current = current->next;
	}
	return (num);
}

int	ft_min_number(t_stack **lst)
{
	t_stack	*current;
	int		min;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}
