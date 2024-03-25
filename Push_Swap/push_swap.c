/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/02/01 13:56:22 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		ft_printf("%s ", (char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	is_sorted;

	is_sorted = ft_lstcheck_sort(stack_a) + ft_lstcheck_sort(stack_b);
	while (is_sorted < 2)
	{
		ft_swap_stacks(stack_a, stack_b);
		if (!ft_lstcheck_sort(stack_a))
			ft_rotation_sort(stack_a, ft_ra, ft_rra);
		if (!ft_lstcheck_sort(stack_b))
			ft_rotation_sort(stack_b, ft_rb, ft_rrb);
		is_sorted = ft_lstcheck_sort(stack_a) + ft_lstcheck_sort(stack_b);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	i = 2;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		stack_a = ft_lstnew(ft_strdup(argv[1]));
		while (argv[i])
		{
			ft_lstadd_back(&stack_a, ft_lstnew(ft_strdup(argv[i])));
			i++;
		}
		size = ft_lstsize(stack_a) / 2;
		while (size--)
			ft_pb(&stack_b, &stack_a);
		ft_lstprint(&stack_b);
		ft_lstprint(&stack_a);
		ft_sort(&stack_a, &stack_b);
		ft_lstprint(&stack_b);
		ft_lstprint(&stack_a);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
