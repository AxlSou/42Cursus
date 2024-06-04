/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:41:39 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 19:23:37 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **lst)
{
	int	tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = tmp;
}

void	ft_sa(t_stack **lst)
{
	ft_swap(lst);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **lst)
{
	ft_swap(lst);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **lst_a, t_stack **lst_b)
{
	ft_swap(lst_a);
	ft_swap(lst_b);
	ft_printf("ss\n");
}

void	ft_swap_stacks(t_stack **lst_a, t_stack **lst_b)
{
	int	is_a_swappable;
	int	is_b_swappable;

	is_a_swappable = (*lst_a)->next && (*lst_a)->content
		> (*lst_a)->next->content && (*lst_a)->content != ft_max_number(lst_a);
	is_b_swappable = (*lst_b)->next && (*lst_b)->content 
		> (*lst_b)->next->content && (*lst_b)->content != ft_max_number(lst_b);
	if (is_a_swappable && is_b_swappable)
		ft_ss(lst_a, lst_b);
	else if (is_a_swappable)
		ft_sa(lst_a);
	else if (is_b_swappable)
		ft_sb(lst_b);
}
