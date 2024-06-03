/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:31 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/03 22:16:21 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct  n_list{
    int     index;
    int     position;
    int     cost;
    int     content;
    struct  n_list *next;
}               l_list;

void	ft_push(l_list **stack_src, l_list **stack_dst);
void	ft_pa(l_list **stack_a, l_list **stack_b);
void	ft_pb(l_list **stack_b, l_list **stack_a);
void	ft_ra(l_list **lst);
void	ft_rb(l_list **lst);
void	ft_rr(l_list **lst_a, l_list **lst_b);
void	ft_rotate(l_list **lst);
void	ft_rotate_lst(l_list **lst_a, l_list **lst_b);
void	ft_sa(l_list **lst);
void	ft_sb(l_list **lst);
void	ft_ss(l_list **lst_a, l_list **lst_b);
void	ft_swap(l_list **lst);
void	ft_rra(l_list **lst);
void	ft_rrb(l_list **lst);
void	ft_rrr(l_list **lst_a, l_list **lst_b);
void	ft_reverse_rotate(l_list **lst);
void	ft_rev_rotate_lst(l_list **lst_a, l_list **lst_b);
int		ft_max_number(l_list **lst);
int	    ft_min_number(l_list **lst);
int		ft_lstcheck_sort(l_list **lst);
void	ft_swap_stacks(l_list **lst_a, l_list **lst_b);
int		ft_check_rotation_sort(l_list **lst);
void	ft_rotation_sort(l_list **lst_a, l_list **lst_b);
int		ft_get_position(l_list **lst, int n);
void	ft_lstprint(l_list **lst);
l_list	*ft_newlst(int content);
void    ft_add_back_lst(l_list **lst, l_list *new_n);
void	ft_add_front_lst(l_list **lst, l_list *new);
l_list  *ft_lastnode(l_list *lst);
void	ft_clearlst(l_list **lst, void (*del)(void *));
void	ft_set_index(l_list **stack);

#endif