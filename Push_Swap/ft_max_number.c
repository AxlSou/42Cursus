/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:56 by asoubiel          #+#    #+#             */
/*   Updated: 2024/02/01 13:21:42 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_number(t_list **lst)
{
	int		num;
	t_list	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	num = ft_atoi(current->content);
	while (current)
	{
		if (ft_atoi(current->content) > num)
			num = ft_atoi(current->content);
		current = current->next;
	}
	return (num);
}
