/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:51:36 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 11:07:47 by jtollena         ###   ########.fr       */
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
