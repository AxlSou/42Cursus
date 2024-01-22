/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:14 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/22 17:29:13 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstprint(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

int    ft_check_sort(t_list *lst)
{
    char *value;

    value = lst->content;
    while (lst)
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
        stack_b = ft_lstnew(ft_strdup(argv[size]));
        while (size--)
        {
            ft_lstadd_back(&stack_b, ft_lstnew(ft_strdup(argv[size])));
        }
        ft_lstprint(stack_a);
        ft_lstprint(stack_b);
        printf("Stack a: %d\n", ft_check_sort(stack_a));
        printf("Stack b: %d\n", ft_check_sort(stack_b));
    }
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}