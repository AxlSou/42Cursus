/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:13 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/04 19:23:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **lst)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	last = ft_lastnode(*lst);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_add_front_lst(lst, last);
	tmp->next = NULL;
}

void	ft_rra(t_stack **lst)
{
	if(lst)
	{
		ft_reverse_rotate(lst);
		ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack **lst)
{
	if(lst)
	{
		ft_reverse_rotate(lst);
		ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack **lst_a, t_stack **lst_b)
{
	if (lst_a && lst_b)
	{
		ft_reverse_rotate(lst_a);
		ft_reverse_rotate(lst_b);
		ft_printf("rrr\n");
	}
}

void	ft_rev_rotate_lst(t_stack **lst_a, t_stack **lst_b)
{
	if (!ft_lstcheck_sort(lst_a) && !ft_lstcheck_sort(lst_b))
		ft_rrr(lst_a, lst_b);
	else if (!ft_lstcheck_sort(lst_a))
		ft_rra(lst_a);
	else if (!ft_lstcheck_sort(lst_b))
		ft_rrb(lst_b);
}
