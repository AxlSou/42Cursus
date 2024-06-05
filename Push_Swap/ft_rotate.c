/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:45:59 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 20:11:38 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	last = ft_lastnode(*lst);
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_ra(t_stack **lst)
{
	if(lst)
	{
		ft_rotate(lst);
		ft_printf("ra\n");
	}
}

void	ft_rb(t_stack **lst)
{
	if (lst)
	{
		ft_rotate(lst);
		ft_printf("rb\n");
	}
	
}

void	ft_rr(t_stack **lst_a, t_stack **lst_b)
{
	if (lst_a && lst_b)
	{
		ft_rotate(lst_a);
		ft_rotate(lst_b);
		ft_printf("rr\n");
	}
	
}

void	ft_rotate_lst(t_stack **lst_a, t_stack **lst_b)
{
	if (!ft_lstcheck_sort(lst_a) && !ft_lstcheck_sort(lst_b))
		ft_rr(lst_a, lst_b);
	else if (!ft_lstcheck_sort(lst_a))
		ft_ra(lst_a);
	else if (!ft_lstcheck_sort(lst_b))
		ft_rb(lst_b);
}