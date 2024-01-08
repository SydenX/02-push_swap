/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/08 13:17:06 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


/* SWAP PART */
void	sa(t_stack *a, int ss)
{
	int	cpy;

	cpy = a->nbrs[1];
	a->nbrs[1] = a->nbrs[0];
	a->nbrs[0] = cpy;
	if (ss == 0)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int ss)
{
	int	cpy;

	cpy = b->nbrs[1];
	b->nbrs[1] = b->nbrs[0];
	b->nbrs[0] = cpy;
	if (ss == 0)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sa(b, 1);
	ft_printf("ss\n");
}

/* MOVE FIRST INT PART */

void	remove_top(t_stack *s)
{
	int		i;

	i = 0;
	while (i < s->size - 1)
	{
		s->nbrs[i] = s->nbrs[i + 1];
		i++;
	}
	s->size = s->size - 1;
}

void	put_in(t_stack *s, t_stack *rem)
{
	int	i;
	int	nb;

	nb = rem->nbrs[0];
	if (s->size > 0)
	{
		i = s->size - 1;
		s->nbrs[s->size] = s->nbrs[s->size - 1];
		while (i > 0)
		{
			s->nbrs[i] = s->nbrs[i - 1];
			i--;
		}
		s->nbrs[i] = nb;
	}
	else
		s->nbrs[0] = nb;
	s->size = s->size + 1;
	remove_top(rem);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		put_in(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		put_in(b, a);
	ft_printf("pb\n");
}

/* FIRST BECOME LAST ROTATE PART */

void	ra(t_stack *a, int rr)
{
	int	first;
	int	i;

	i = 0;
	first = a->nbrs[0];
	while (i < a->size)
	{
		a->nbrs[i] = a->nbrs[i + 1];
		i++;
	}
	a->nbrs[i - 1] = first;
	if (rr == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int rr)
{
	int	first;
	int	i;

	i = 0;
	first = b->nbrs[0];
	while (i < b->size)
	{
		b->nbrs[i] = b->nbrs[i + 1];
		i++;
	}
	b->nbrs[i - 1] = first;
	if (rr == 0)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	ra(b, 1);
	ft_printf("rr\n");
}

/* LAST BECOME FIRST ROTATE PART */

void	rra(t_stack *a, int rrr)
{
	int	last;
	int	i;

	i = a->size;
	last = a->nbrs[i - 1];
	while (i > 0)
	{
		a->nbrs[i] = a->nbrs[i - 1];
		i--;
	}
	a->nbrs[i] = last;
	if (rrr == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int rrr)
{
	int	last;
	int	i;

	i = b->size;
	last = b->nbrs[i - 1];
	while (i > 0)
	{
		b->nbrs[i] = b->nbrs[i - 1];
		i--;
	}
	b->nbrs[i] = last;
	if (rrr == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rra(b, 1);
	ft_printf("rrr\n");
}
