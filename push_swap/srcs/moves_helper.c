/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:57:22 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 14:42:13 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	go_top_loop(int moves, int place, int stack, t_stack *a)
{
	while (place != 0)
	{
		place--;
		moves++;
		if (stack == 1)
			ra(a, 0);
		else
			rb(a, 0);
	}
	return (moves);
}

int	go_down_loop(int moves, int place, int stack, t_stack *a)
{
	while (place != 0)
	{
		place--;
		moves++;
		if (stack == 1)
			ra(a, 0);
		else
			rb(a, 0);
	}
	if (place == 0)
	{
		moves++;
		if (stack == 1)
			ra(a, 0);
		else
			rb(a, 0);
	}
	return (moves);
}
