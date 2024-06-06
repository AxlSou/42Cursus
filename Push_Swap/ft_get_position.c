/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:36:29 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/06 20:24:09 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_position(t_stack **lst, int n)
{
	t_stack	*current;
	int		result;

	current = *lst;
	result = 1;
	if (!lst)
		return (0);
	while (current)
	{
		if (current->content == n)
			return (result);
		current = current->next;
		result++;
	}
	return (0);
}
