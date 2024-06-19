/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:41:39 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/18 20:21:20 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;

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
