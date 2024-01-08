/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:15 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/08 12:20:35 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft.h"

typedef struct s_stack {
	int	*nbrs;
	int	size;
}	t_stack;
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

#endif