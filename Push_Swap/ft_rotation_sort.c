/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/16 10:03:11 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_get_cheapest(t_stack **lst)
{
	t_stack	*result;
	t_stack	*current;

	current = *lst;
	result = NULL;
	while (current)
	{
		if (!result || current->cost < result->cost)
			result = current;
		current = current->next;
	}
	return (result);
}

static t_stack	*ft_get_target(t_stack **lst_a, int pos)
{
	t_stack	*current;

	if (!lst_a || !*lst_a)
		return (NULL);
	current = *lst_a;
	while (current)
	{
		if (current->position == pos)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static void	ft_rotation_b(t_stack **lst_b, t_stack *chpst, int size_b)
{
	if (chpst->position && chpst->position < size_b / 2)
		ft_rb(lst_b);
	else if (chpst->position)
		ft_rrb(lst_b);
}

static void	ft_rotation_a(t_stack **lst_a, t_stack *target, int size_a)
{
	if (target->position && target->position < size_a / 2)
		ft_ra(lst_a);
	else if (target->position)
		ft_rra(lst_a);
}

void	ft_rotation_sort(t_stack **lst_a, t_stack **lst_b,
							int size_a, int size_b)
{
	t_stack	*chpst;
	t_stack	*target;

	if (!lst_a || !lst_b || !*lst_a || !*lst_b)
		return ;
	chpst = ft_get_cheapest(lst_b);
	target = ft_get_target(lst_a, chpst->target_pos);
	while (chpst->position || target->position)
	{
		if ((chpst->position < size_b / 2 && target->position < size_a / 2)
			&& (chpst->position && target->position))
			ft_rr(lst_a, lst_b);
		else if ((chpst->position > size_b / 2 && target->position > size_a / 2)
			&& (chpst->position && target->position))
			ft_rrr(lst_a, lst_b);
		else
		{
			ft_rotation_b(lst_b, chpst, size_b);
			ft_rotation_a(lst_a, target, size_a);
		}
		chpst->position = ft_get_position(lst_b, chpst->content);
		target->position = ft_get_position(lst_a, target->content);
	}
	ft_pa(lst_a, lst_b);
}
