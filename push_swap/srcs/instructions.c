/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/21 10:33:15 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"


/* SWAP PART */
void	sa(t_stack *a)
{
	int	cpy;

	cpy = a->nbrs[1];
	a->nbrs[1] = a->nbrs[0];
	a->nbrs[0] = cpy;
}

void	sb(t_stack *b)
{
	int	cpy;

	cpy = b->nbrs[1];
	b->nbrs[1] = b->nbrs[0];
	b->nbrs[0] = cpy;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
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
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		put_in(b, a);
}

/* FIRST BECOME LAST ROTATE PART */

void	ra(t_stack *a)
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
}

void	rb(t_stack *b)
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
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
}

/* LAST BECOME FIRST ROTATE PART */

void	rra(t_stack *a)
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
}

void	rrb(t_stack *b)
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
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rra(b);
}
