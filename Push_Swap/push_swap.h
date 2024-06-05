/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:31 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/05 20:43:08 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack {
	int				index;
	int				position;
	int				cost;
	int				target_pos;
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_push(t_stack **stack_src, t_stack **stack_dst);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **lst);
void	ft_rb(t_stack **lst);
void	ft_rr(t_stack **lst_a, t_stack **lst_b);
void	ft_rotate(t_stack **lst);
void	ft_rotate_lst(t_stack **lst_a, t_stack **lst_b);
void	ft_sa(t_stack **lst);
void	ft_sb(t_stack **lst);
void	ft_ss(t_stack **lst_a, t_stack **lst_b);
void	ft_swap(t_stack **lst);
void	ft_rra(t_stack **lst);
void	ft_rrb(t_stack **lst);
void	ft_rrr(t_stack **lst_a, t_stack **lst_b);
void	ft_reverse_rotate(t_stack **lst);
void	ft_rev_rotate_lst(t_stack **lst_a, t_stack **lst_b);
int		ft_max_number(t_stack **lst);
int		ft_min_number(t_stack **lst);
int		ft_lstcheck_sort(t_stack **lst);
void	ft_swap_stacks(t_stack **lst_a, t_stack **lst_b);
int		ft_check_rotation_sort(t_stack **lst);
void	ft_rotation_sort(t_stack **lst_a, t_stack **lst_b);
int		ft_get_position(t_stack **lst, int n);
void	ft_lstprint(t_stack **lst);
t_stack	*ft_newlst(int content);
void	ft_add_back_lst(t_stack **lst, t_stack *new_n);
void	ft_add_front_lst(t_stack **lst, t_stack *new);
t_stack	*ft_lastnode(t_stack *lst);
void	ft_clearlst(t_stack **lst, void (*del)(void *));
void	ft_set_index(t_stack **stack);
int		ft_sizelst(t_stack **lst);
void	ft_move_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);

#endif