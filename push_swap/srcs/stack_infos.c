/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:26:49 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 11:13:06 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	max(t_stack s)
{
	int		i;
	long	max;

	i = 0;
	max = -2147483649;
	while (i < s.size)
	{
		if (s.nbrs[i] > max)
			max = s.nbrs[i];
		i++;
	}
	return (max);
}

int	min(t_stack s)
{
	int		i;
	long	min;

	i = 0;
	min = 2147483648;
	while (i < s.size)
	{
		if (s.nbrs[i] < min)
			min = s.nbrs[i];
		i++;
	}
	return (min);
}

int	ft_nearest(int nb, t_stack b)
{
	int		i;
	int		nearest;

	i = 0;
	nearest = max(b);
	while (i < b.size)
	{
		if (abs(nb - nearest) > abs(nb - b.nbrs[i]))
			nearest = b.nbrs[i];
		i++;
	}
	return (nearest);
}
