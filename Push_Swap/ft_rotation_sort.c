/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:04 by asoubiel          #+#    #+#             */
/*   Updated: 2024/02/01 14:47:56 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotation_dir(t_list **lst)
{
	int	size;
	int	max;
	int	position;

	size = ft_lstsize(*lst);
	max = ft_max_number(lst);
	position = ft_get_position(lst, max);
	if (position < size / 2)
		return ("r");
	else
		return ("rr");
}

void	ft_rotation_sort(t_list **lst_a, t_list **lst_b,
		void (*r)(t_list **, t_list **), void (*rr)(t_list **, t_list **))
{
	char	*dir_a;
	char	*dir_b;

	dir_a = ft_rotation_dir(lst_a);
	dir_b = ft_rotation_dir(lst_b);
	// Hay que seguir viendo la posibilidad de hacerlo para ambos stacks
	// Solo estoy checkeando una lista en el proximo if
	if (ft_check_rotation_sort(lst))
	{
		if (dir_a == "r" && dir_b == "r")
			r(lst_a, lst_b);
		else
			rr(lst_a, lst_b);
	}
	else
		r(lst_a, lst_b);
}

