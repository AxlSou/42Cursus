/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 07:58:10 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/19 21:32:35 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_final_rotation(t_stack **lst_a)
{
	int	size;
	int	min;
	int	position;

	size = ft_sizelst(lst_a);
	min = ft_min_number(lst_a);
	position = ft_get_position(lst_a, min);
	if (position < size / 2)
	{
		while ((*lst_a)->content != min)
			ft_ra(lst_a);
	}
	else
	{
		while ((*lst_a)->content != min)
			ft_rra(lst_a);
	}
}

static void	ft_sort_two(t_stack **lst_a)
{
	t_stack	*current;

	current = *lst_a;
	if (current->content > current->next->content)
		ft_sa(lst_a);
}

void	ft_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_sizelst(lst_a);
	if (size_a == 2)
		ft_sort_two(lst_a);
	else if (ft_lstcheck_sort(lst_a))
		return ;
	else
	{
		ft_set_index(lst_a);
		ft_move_to_b(lst_a, lst_b);
		ft_sort_three(lst_a);
		while (*lst_b)
		{
			size_a = ft_sizelst(lst_a);
			size_b = ft_sizelst(lst_b);
			ft_set_position(lst_a, lst_b);
			ft_set_target_pos(lst_a, lst_b);
			ft_set_cost(lst_a, lst_b, size_a, size_b);
			ft_rotation_sort(lst_a, lst_b, size_a, size_b);
		}
		ft_final_rotation(lst_a);
	}
}
