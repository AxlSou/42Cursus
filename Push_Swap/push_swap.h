/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:31 by asoubiel          #+#    #+#             */
/*   Updated: 2024/01/23 23:49:39 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

void    ft_push(t_list **stack_src, t_list **stack_dst);
void    ft_pa(t_list **stack_a, t_list **stack_b);
void    ft_pb(t_list **stack_b, t_list **stack_a);
void    ft_ra(t_list **lst);
void    ft_rb(t_list **lst);
void    ft_rr(t_list **lst_a, t_list **lst_b);
void    ft_rotate(t_list **lst);
void    ft_sa(t_list **lst);
void    ft_sb(t_list **lst);
void    ft_ss(t_list **lst_a, t_list **lst_b);
void    ft_swap(t_list **lst);

#endif