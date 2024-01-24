/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/23 23:56:33 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstprint(t_list *lst)
{
    t_list *current;

    current = lst;
    while (current)
    {
        ft_printf("%s ", (char *)current->content);
        current = current->next;
    }
    ft_printf("\n");
}

int    ft_lstcheck_sort(t_list *lst)
{
    char *value;

    value = lst->content;
    while (lst->next)
    {
        if (ft_atoi(lst->content) < ft_atoi(value))
            return (0);
        value = lst->content;
        lst = lst->next;
    }
    return (1);
}

int main(int argc, char** argv)
{
    int i;
    t_list *stack_a;
    t_list *stack_b;
    int size;

    i = 2;
    stack_b = NULL;
    if (argc < 2)
        return (0);
    else
    {
        stack_a = ft_lstnew(ft_strdup(argv[1]));
        while (argv[i++])
            ft_lstadd_back(&stack_a, ft_lstnew(ft_strdup(argv[i])));
        size = ft_lstsize(stack_a) / 2;
        while (size--)
            ft_pb(&stack_b, &stack_a);
        ft_lstprint(stack_a);
        ft_lstprint(stack_b);
    }
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}
