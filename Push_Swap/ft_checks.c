/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:36:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/02/01 11:36:44 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstcheck_sort(t_list **lst)
{
	char	*value;
	t_list	*current;

	current = *lst;
	value = current->content;
	while (current)
	{
		if (ft_atoi(current->content) < ft_atoi(value))
			return (0);
		value = current->content;
		current = current->next;
	}
	return (1);
}

int	ft_check_rotation_sort(t_list **lst)
{
	int		max_num;
	t_list	*current;

	max_num = ft_max_number(lst);
	current = *lst;
	while (current->next)
	{
		if (ft_atoi(current->content) < ft_atoi(current->next->content)
			|| ft_atoi(current->content) == max_num)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
