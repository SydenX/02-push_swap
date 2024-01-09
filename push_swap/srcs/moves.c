/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:40 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 12:11:14 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	are_same_move(int nba, t_stack a, int nbb, t_stack b)
{
	int	placea;
	int placeb;

	placea = get_placein(nba, a);
	placeb = get_placein(nbb, b);
	if (placeb == 0 || placea == 0)
		return (0);
	if (get_placein(nba, a) + 1 > a.size / 2 && get_placein(nbb, b) + 1 > b.size / 2)
		return 1;
	else if (get_placein(nba, a) + 1 <= a.size / 2 && get_placein(nbb, b) + 1 <= b.size / 2)
		return 1;
	return (0);
}

int	moves_two_totop(int nba, t_stack a, int nbb, t_stack b)
{
	int	moves;
	int	placea;

	moves = 0;
	placea = get_placein(nba, a);
	placeb = get_placein(nba, a);
	if (are_same_move(nba, a, nbb, b) == 1)
	{
		if (get_placein(nba, a) + 1 > a.size / 2 && get_placein(nbb, a) + 1 > b.size / 2)
		{
			while (placea != a.size && placeb != b.size){
				placea++;
				placeb++;
				moves++;
			}
		}
		else
		{
			while (placea != 0 && placeb != 0){
				placea--;
				placeb--;
				moves++;
			}
		}
	}
	return (moves);
}

int	moves_totop(int nb, t_stack a)
{
	int	moves;
	int	place;

	moves = 0;
	place = get_placein(nb, a);
	if (place == 0)
		return (0);
	if (get_placein(nb, a) + 1 > a.size / 2)
	{
		while (place != a.size)
		{
			place++;
			moves++;
		}
	}
	else
	{
		while (place != 0)
		{
			place--;
			moves++;
		}
	}
	return (moves);
}

int	moves_todown(int nb, t_stack a, int moves)
{
	int	place;

	place = get_placein(nb, a);
	if (place == a.size - 1)
		return (0);
	if (get_placein(nb, a) + 1 > a.size / 2)
	{
		while (place != a.size - 1)
		{
			place++;
			moves++;
		}
	}
	else
	{
		while (place != 0)
		{
			place--;
			moves++;
		}
		if (place == 0)
			moves++;
	}
	return (moves);
}

int	go_top(int nb, t_stack *a, int stack, int moves)
{
	int	place;

	place = get_placein(nb, *a);
	if (place == 0)
		return (0);
	if (get_placein(nb, *a) + 1 > (*a).size / 2)
	{
		while (place != (*a).size)
		{
			place++;
			moves++;
			if (stack == 1)
				rra(a, 0);
			else
				rrb(a, 0);
		}
	}
	else
		moves = go_top_loop(moves, place, stack, a);
	return (moves);
}

int	go_down(int nb, t_stack *a, int stack, int moves)
{
	int	place;

	place = get_placein(nb, *a);
	if (place == 0)
		return (0);
	if (get_placein(nb, *a) + 1 > (*a).size / 2)
	{
		while (place != (*a).size - 1)
		{
			place++;
			moves++;
			if (stack == 1)
				rra(a, 0);
			else
				rrb(a, 0);
		}
	}
	else
		moves = go_down_loop(moves, place, stack, a);
	return (moves);
}

int	go_nearest(int nb, t_stack *a, t_stack *b)
{
	int	actions;
	int	i;
	int	nearest;

	actions = 0;
	nearest = ft_nearest(nb, *b);
	if (nearest < nb)
		actions += go_top(nearest, b, 0, 0);
	else
		actions += go_down(nearest, b, 0, 0);
	return (actions);
}
