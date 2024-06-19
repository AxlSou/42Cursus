/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/18 21:39:38 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_stack **lst)
{
	t_stack	*current;

	current = *lst;
	if (!lst || !current)
		return ;
	while (current)
	{
		printf("%d - index: %d - position: %d - target_pos: %d - cost: %d\n",
			current->content, current->index, current->position, current->target_pos, current->cost);
		current = current->next;
	}
	printf("\n");
}

static void	ft_new_stack(t_stack **stack_a, char *argv)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(argv, ' ');
	while (split[i])
	{
		ft_add_back_lst(stack_a, ft_newlst(ft_atol(split[i])));
		i++;
	}
	free(split);
}

static void	ft_push_swap(char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 2;
	stack_b = NULL;
	stack_a = NULL;
	ft_new_stack(&stack_a, argv[1]);
	while (argv[i])
	{
		ft_new_stack(&stack_a, argv[i]);
		i++;
	}
	ft_lstcheck_dup(&stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_clearlst(&stack_a, free);
	ft_clearlst(&stack_b, free);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		ft_push_swap(argv);
	return (0);
}
