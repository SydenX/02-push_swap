/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:25:43 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 11:55:59 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
int	get_placein(int nb, t_stack s)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		if (s.nbrs[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	moves_togo(int nb, t_stack a, t_stack b)
{
	int	moves;
	int	i;
	int	smaller;
	int	nearest;

	moves = moves_totop(nb, a);
	nearest = ft_nearest(nb, b);
	if (nearest < nb)
		moves += moves_totop(nearest, b);
	else
		moves += moves_todown(nearest, b, 0);
	return (moves + 1);
}

int	check_smaller_change(t_stack *a, t_stack *b)
{
	long	smaller;
	int		smallerint;
	int		i;

	smaller = 2147483648;
	smallerint = a->nbrs[0];
	i = 0;
	while (i < a->size)
	{
		if (moves_togo(a->nbrs[i], *a, *b) < smaller)
		{
			smaller = moves_togo(a->nbrs[i], *a, *b);
			smallerint = a->nbrs[i];
		}
		i++;
	}
	return (smallerint);
}
