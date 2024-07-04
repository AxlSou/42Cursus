/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:36:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/27 19:25:33 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstcheck_sort(t_stack **lst)
{
	int		value;
	t_stack	*current;

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

void	ft_lstcheck_dup(t_stack **lst)
{
	t_stack	*current;
	t_stack	*aux;

	current = *lst;
	while (current)
	{
		aux = current->next;
		while (aux)
		{
			if (current->content == aux->content)
			{
				ft_clearlst(lst, free);
				ft_error();
			}
			aux = aux->next;
		}
		current = current->next;
	}
}
