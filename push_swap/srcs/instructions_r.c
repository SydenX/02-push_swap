/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 15:17:05 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
