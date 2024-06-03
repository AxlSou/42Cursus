/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/01 14:44:23 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_number(l_list **lst)
{
	int		num;
	l_list	*current;

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

int	ft_min_number(l_list **lst)
{
	int		num;
	l_list	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	num = current->content;
	while (current)
	{
		if (current->content < num)
			num = current->content;
		current = current->next;
	}
	return (num);
}