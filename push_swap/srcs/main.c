/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:54 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/08 15:18:51 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(0);
}

void	print_stack(t_stack s)
{
	int	i = 0;
	while (i < s.size)
		ft_printf("%d ", s.nbrs[i++]);
	ft_printf("\n");
}

int	are_int(char **argv, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicated(t_stack stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < stack.size)
	{
		j = 0;
		k = 0;
		while (j < stack.size)
		{
			if (stack.nbrs[j] == stack.nbrs[i])
			{
				if (k == 1)
					return (1);
				else
					k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack.size)
	{
		if (stack.nbrs[i] > stack.nbrs[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_placein(int	nb, t_stack s)
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

int	moves_todown(int nb, t_stack a)
{
	int	moves;
	int	place;

	moves = 0;
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

int	max(t_stack s)
{
	int i = 0;
	int max = -2147483648;
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
	int i = 0;
	int min = 2147483647;
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
	int	i = 0;
	int	nearest = max(b);
	while (i < b.size)
	{
		if (abs(nb - nearest) > abs(nb - b.nbrs[i]))
			nearest = b.nbrs[i];
		i++;
	}
	return (nearest);
}

void *next = NULL;
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
		moves += moves_todown(nearest, b);
	return (moves + 1);
}

int	check_smaller_change(t_stack *a, t_stack *b)
{
	int smaller = 2147483647;
	int smallerInt = a->nbrs[0];
	int i = 0;
	while (i < a->size)
	{
		if (moves_togo(a->nbrs[i], *a, *b) < smaller){
			smaller = moves_togo(a->nbrs[i], *a, *b);
			smallerInt = a->nbrs[i];
		}
		i++;
	}
	return (smallerInt);
}

int go_top(int nb, t_stack *a, int stack)
{
	int	moves;
	int	place;

	moves = 0;
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
	}
	return (moves);
}

int go_down(int nb, t_stack *a, int stack)
{
	int	moves;
	int	place;

	moves = 0;
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
		if(place == 0){
			moves++;
			if (stack == 1)
				ra(a, 0);
			else
				rb(a, 0);
		}
	}
	return (moves);
}

int go_nearest(int nb, t_stack *a, t_stack *b)
{
	int actions = 0;
	int	i;
	int	nearest;

	nearest = ft_nearest(nb, *b);
	if (nearest < nb)
		actions += go_top(nearest, b, 0);
	else
		actions += go_down(nearest, b, 0);
	return (actions);
}

int	go_smaller_change(t_stack *a, t_stack *b)
{
	int actions = 0;
	int	smaller = check_smaller_change(a, b);
	actions += go_top(smaller, a, 1);
	actions += go_nearest(smaller, a, b);
	pb(a, b);
	actions += 1;
	return (actions);
}

int set_higher(int nb, t_stack *a, t_stack *b)
{
	int higher = 2147483647;
	int i = 0;
	int hashigher = 0;
	int actions = 0;
	while (i < a->size)
	{
		if (a->nbrs[i] > nb && a->nbrs[i] < higher){
			higher = a->nbrs[i];
			hashigher = 1;
		}
		i++;
	}
	if (hashigher == 1){
		actions = go_top(higher, a, 1) + 1;
		pa(a, b);
		return (actions);
	}
	 else {
		actions = go_top(min(*a), a, 1) + 1;
		pa(a, b);
		return (1);
	}
}

void	execute(t_stack *a, t_stack *b, int actions)
{
	if (actions == 0)
	{
		pb(a, b);
		pb(a, b);
		actions += 2;
	}
	// print_stack(*a);
	// print_stack(*b);
	// ft_printf("tg>%d\n", moves_togo(2, *a, *b));
	// ft_printf("near>%d\n", ft_nearest(2, *b));
	// ft_printf("smaller>%d\n", check_smaller_change(a, b));

	while (a->size > 3)
	{
		actions += go_smaller_change(a, b);
	}
	if (a->nbrs[1] < a->nbrs[0]){
		sa(a, 0);
		actions++;
	}
	if (a->nbrs[2] < a->nbrs[1]){
		rra(a, 0);
		actions++;
	}
	if (a->nbrs[1] < a->nbrs[0]){
		sa(a, 0);
		actions++;
	}
	// print_stack(*a);
	// print_stack(*b);
	int i = 0;
	while (b->size > 0)
	{
		// ft_printf("high of %d is %d\n", b->nbrs[i], set_higher(b->nbrs[i], a, b));
		i++;
		actions += set_higher(b->nbrs[0], a, b);
	}
	while (!sorted(*a))
	{
		rra(a, 0);
		actions++;
	}
	
	// ft_printf("\nActions>%d\n", actions);./co
	// print_stack(*a);
}

void	create_stacks(char **argv, int size)
{
	int		i;
	t_stack stack_a;
	t_stack stack_b;

	stack_a.nbrs = malloc((size - 1) * sizeof(int));
	stack_b.nbrs = malloc((size - 1) * sizeof(int));

	i = 0;
	while (i < size - 1)
	{
		stack_a.nbrs[i] = ft_atoi(argv[i]);
		i++;
	}
	stack_a.size = i;
	stack_b.size = 0;
	if (duplicated(stack_a))
		error("Do not put duplicated numbers.");
	if (sorted(stack_a))
		error("List already sorted.");
	execute(&stack_a, &stack_b, 0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		error("Put at least two numbers to sort.");
	else if (!are_int(argv, argc))
		error("Please only put numbers.");
	else if (argc > 2)
		create_stacks(&argv[1], argc);
	return (1);
}
