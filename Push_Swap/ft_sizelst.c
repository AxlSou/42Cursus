/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:43:16 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 20:11:44 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sizelst(t_stack **lst)
{
	int		count;
	t_stack	*current;

	current = *lst;
	count = 1;
	if (!lst)
		return (0);
	while (current->next)
	{
		current = current->next;
		count++;
	}
	return (count);
}
