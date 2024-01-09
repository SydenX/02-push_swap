/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:57 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
