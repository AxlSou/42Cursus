/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/27 20:43:48 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_new_stack(t_stack **stack_a, char *argv)
{
	int		i;
	char	**split;
	int		error;

	i = 0;
	error = 0;
	split = ft_split(argv, ' ');
	while (split[i])
	{
		ft_add_back_lst(stack_a, ft_newlst(ft_atol(split[i], &error, 0)));
		free(split[i]);
		i++;
	}
	free(split);
	if (error == -1)
	{
		ft_clearlst(stack_a, free);
		ft_error();
	}
}

static void	ft_push_swap(char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
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
