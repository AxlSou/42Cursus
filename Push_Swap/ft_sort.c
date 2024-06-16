/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 07:58:10 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/16 10:04:08 by asoubiel         ###   ########.fr       */
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

void	ft_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	size_a;
	int	size_b;

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
