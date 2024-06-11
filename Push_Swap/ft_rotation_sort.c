/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/11 21:17:17 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_rotation_dir(t_stack **lst)
{
	int	size;
	int	max;
	int	position;

	size = ft_sizelst(*lst);
	max = ft_max_number(lst);
	position = ft_get_position(lst, max);
	if (position < size / 2)
		return (1);
	else
		return (0);
}

void	ft_rotation_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	dir_a;
	int	dir_b;
	int	is_sorted;

	is_sorted = ft_lstcheck_sort(lst_a) + ft_lstcheck_sort(lst_b);
	dir_a = ft_rotation_dir(lst_a);
	dir_b = ft_rotation_dir(lst_b);
	while (is_sorted < 2)
	{
		ft_swap_stacks(lst_a, lst_b);
		ft_rotate_lst(lst_a, lst_b);
		is_sorted = ft_lstcheck_sort(lst_a) + ft_lstcheck_sort(lst_b);
	}
}
