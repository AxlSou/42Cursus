/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/03 22:20:14 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(l_list **lst)
{
	l_list	*current;

	current = *lst;
	if(!lst || !current)
		return ;
	while (current)
	{
		ft_printf("%d - index: %d\n", current->content, current->index);
		current = current->next;
	}
	ft_printf("\n");
}

// void	ft_sort(t_list **stack_a, t_list **stack_b)
// {
	
// }

int	main(int argc, char **argv)
{
	int		i;
	l_list	*stack_a;
	l_list	*stack_b;

	i = 2;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		stack_a = ft_newlst(ft_atoi(argv[1]));
		while (argv[i])
		{
			ft_add_back_lst(&stack_a, ft_newlst(ft_atoi(argv[i])));
			i++;
		}
		ft_set_index(&stack_a);
		ft_lstprint(&stack_a);
	}
	ft_clearlst(&stack_a, free);
	ft_clearlst(&stack_b, free);
	return (0);
}
