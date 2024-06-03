/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:36:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/01 14:44:55 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstcheck_sort(l_list **lst)
{
	int		value;
	l_list	*current;

	current = *lst;
	value = current->content;
	while (current)
	{
		if (current->content < value)
			return (0);
		value = current->content;
		current = current->next;
	}
	return (1);
}

int	ft_check_rotation_sort(l_list **lst)
{
	int		max_num;
	l_list	*current;

	max_num = ft_max_number(lst);
	current = *lst;
	while (current->next)
	{
		if (current->content < current->next->content
			|| current->content == max_num)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
