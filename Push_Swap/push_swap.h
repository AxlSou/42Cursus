/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoubiel <asoubiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:15:31 by asoubiel          #+#    #+#             */
/*   Updated: 2024/06/18 20:21:50 by asoubiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				position;
	int				cost;
	int				target_pos;
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **lst);
void	ft_rb(t_stack **lst);
void	ft_rr(t_stack **lst_a, t_stack **lst_b);
void	ft_sa(t_stack **lst);
void	ft_sb(t_stack **lst);
void	ft_ss(t_stack **lst_a, t_stack **lst_b);
void	ft_rra(t_stack **lst);
void	ft_rrb(t_stack **lst);
void	ft_rrr(t_stack **lst_a, t_stack **lst_b);
int		ft_max_number(t_stack **lst);
int		ft_min_number(t_stack **lst);
int		ft_lstcheck_sort(t_stack **lst);
void	ft_rotation_sort(t_stack **lst_a, t_stack **lst_b,
			int size_a, int size_b);
void	ft_set_position(t_stack **stack_a, t_stack **stack_b);
int		ft_get_position(t_stack **lst, int n);
void	ft_sort(t_stack **lst_a, t_stack **lst_b);
t_stack	*ft_newlst(int content);
void	ft_add_back_lst(t_stack **lst, t_stack *new_n);
void	ft_add_front_lst(t_stack **lst, t_stack *new);
t_stack	*ft_lastnode(t_stack *lst);
void	ft_clearlst(t_stack **lst, void (*del)(void *));
void	ft_set_index(t_stack **stack);
int		ft_sizelst(t_stack **lst);
void	ft_move_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
void	ft_set_target_pos(t_stack **stack_a, t_stack **stack_b);
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b,
			int size_a, int size_b);
void	ft_lstcheck_dup(t_stack **lst);
void	ft_error(void);
int		ft_atol(const char *str);
void	ft_lstprint(t_stack **lst);

#endif