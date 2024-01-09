/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:27:27 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 15:35:00 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	go_smaller_change(t_stack *a, t_stack *b)
{
	int	smaller;
	int	nearest;

	smaller = check_smaller_change(a, b);
	nearest = ft_nearest(smaller, *b);
	go_top(smaller, a, 1, 0);
	go_nearest(smaller, a, b);
	pb(a, b);
}

void	set_higher(int nb, t_stack *a, t_stack *b, int i)
{
	long	higher;
	int		hashigher;

	hashigher = 0;
	higher = 2147483648;
	while (i < a->size)
	{
		if (a->nbrs[i] > nb && a->nbrs[i] < higher)
		{
			higher = a->nbrs[i];
			hashigher = 1;
		}
		i++;
	}
	if (hashigher == 1)
	{
		go_top(higher, a, 1, 0);
		pa(a, b);
	}
	else 
	{
		go_top(min(*a), a, 1, 0);
		pa(a, b);
	}
}

void	sort_three(t_stack *a)
{
	if (a->nbrs[0] > a->nbrs[1])
		sa(a, 0);
	if (a->nbrs[1] > a->nbrs[2])
		rra(a, 0);
	if (a->nbrs[0] > a->nbrs[1])
		sa(a, 0);
}

void	execute(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->size <= 5 && a->nbrs[0] > a->nbrs[a->size - 1])
		rra(a, 0);
	if (sorted(*a))
		return ;
	pb(a, b);
	pb(a, b);
	while (a->size > 3)
		go_smaller_change(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		i++;
		set_higher(b->nbrs[0], a, b, 0);
	}
	while (!sorted(*a))
		rra(a, 0);
}
