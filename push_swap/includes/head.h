/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:15 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 15:01:39 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"
#include <stdio.h>
typedef struct s_stack {
	int	*nbrs;
	int	size;
}	t_stack;
int count;
void print_stack(t_stack s);

void	sa(t_stack *a, int ss);
void	sb(t_stack *b, int ss);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a, int rr);
void	rb(t_stack *b, int rr);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a, int rrr);
void	rrb(t_stack *b, int rrr);
void	rrr(t_stack *a, t_stack *b);

//utils
void	error(int n);
int		get_int_in_str(char *str);
void	print_stack(t_stack s);
int		are_int(char **argv, int size);
int		duplicated(t_stack stack);
int		sorted(t_stack stack);

//stack_infos
int		max(t_stack s);
int		min(t_stack s);
int		ft_nearest(int nb, t_stack b);

//sort
void	go_smaller_change(t_stack *a, t_stack *b);
void	set_higher(int nb, t_stack *a, t_stack *b, int i);
void	sort_three(t_stack *a);
void	execute(t_stack *a, t_stack *b);

//moves
int		moves_totop(int nb, t_stack a);
int		moves_todown(int nb, t_stack a, int moves);
int 	go_top(int nb, t_stack *a, int stack, int moves);
int 	go_down(int nb, t_stack *a, int stack, int moves);
int 	go_nearest(int nb, t_stack *a, t_stack *b);

//moves_helper
int		go_top_loop(int moves, int place, int stack, t_stack *a);
int		go_down_loop(int moves, int place, int stack, t_stack *a);

//main
void	create_stacks(char **argv, int size, int type);
int		main(int argc, char **argv);

//estimations
int		get_placein(int	nb, t_stack s);
int		moves_togo(int nb, t_stack a, t_stack b);
int		check_smaller_change(t_stack *a, t_stack *b);

#endif