/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/20 13:11:46 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

void	pa(t_stack *a, t_stack *b)
{
	if (b->nbrs[0] != 0)
		a->nbrs[0] = b->nbrs[0];
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->nbrs[0] != 0)
		b->nbrs[0] = a->nbrs[0];
}

void	ra(t_stack *a)
{
	int	first;
	int	i;

	i = 0;
	first = a->nbrs[0];
	while (a->nbrs[i + 1] != 0)
	{
		a->nbrs[i] = a->nbrs[i + 1];
		i++;
	}
	a->nbrs[i] = first;
}

void	rb(t_stack *b)
{
	int	first;
	int	i;

	i = 0;
	first = b->nbrs[0];
	while (b->nbrs[i + 1] != 0)
	{
		b->nbrs[i] = b->nbrs[i + 1];
		i++;
	}
	b->nbrs[i] = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
}

int	stacklen(t_stack *s)
{
	int	ln;

	ln = 0;
	while (s->nbrs[ln] != 0)
		ln++;
	return (ln);
}

void	rra(t_stack *a)
{
	int	last;
	int	i;

	i = stacklen(a) - 1;
	last = a->nbrs[i];
	while (a->nbrs[i - 1] != 0)
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

	i = stacklen(b) - 1;
	last = b->nbrs[i];
	while (b->nbrs[i - 1] != 0)
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
