/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:04:13 by asoubiel          #+#    #+#             */
/*   Updated: 2024/02/01 13:48:04 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	last = ft_lstlast(*lst);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(lst, last);
	tmp->next = NULL;
}

void	ft_rra(t_list **lst)
{
	ft_reverse_rotate(lst);
	ft_printf("rra\n");
}

void	ft_rrb(t_list **lst)
{
	ft_reverse_rotate(lst);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	ft_reverse_rotate(lst_a);
	ft_reverse_rotate(lst_b);
	ft_printf("rrr\n");
}

void	ft_rev_rotate_lst(t_list **lst_a, t_list **lst_b)
{
	if (!ft_lstcheck_sort(lst_a) && !ft_lstcheck_sort(lst_b))
		ft_rrr(lst_a, lst_b);
	else if (!ft_lstcheck_sort(lst_a))
		ft_rra(lst_a);
	else if (!ft_lstcheck_sort(lst_b))
		ft_rrb(lst_b);
}
