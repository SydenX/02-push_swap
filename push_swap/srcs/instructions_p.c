/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 11:07:30 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
