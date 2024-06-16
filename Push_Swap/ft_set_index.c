/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:52:52 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/16 10:06:57 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_stack **stack)
{
	t_stack	*current;
	int		i;
	int		value;
	t_stack	*aux;

	current = *stack;
	if (!*stack || !stack)
		return ;
	while (current)
	{
		i = 1;
		aux = *stack;
		value = current->content;
		while (aux)
		{
			if (aux->content < value)
				i++;
			aux = aux->next;
		}
		current->index = i;
		current = current->next;
	}
}
