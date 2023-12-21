/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:54 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/21 13:32:13 by jtollena         ###   ########.fr       */
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

	moves = 1;
	place = get_placein(nb, a);
	if (place == 0)
		return (0);
	if (get_placein(nb, a) > a.size / 2)
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

int	moves_togo(int nb, t_stack a, t_stack b)
{
	int	moves;
	int	i;
	int	smaller;

	moves = moves_totop(nb, a);
	if (b.nbrs[0] > nb)
		return (moves + 1);
	else
	{
		i = 0;
		smaller = b.size;
		while (i < b.size)
		{
			if (moves_totop(b.nbrs[i], b) < smaller && nb > b.nbrs[i])
				smaller = moves_totop(b.nbrs[i], b);
			i++;
		}
		moves += smaller;
	}
	return (moves + 1);
}

void	execute(t_stack *a, t_stack *b, int actions)
{
	if (actions == 0)
	{
		pb(a, b);
		ft_printf("PB\n");
		pb(a, b);
		ft_printf("PB\n");
		actions += 2;
	}
	ft_printf("%d\n", moves_togo(87, *a, *b));

	// return ;
	// if (a->nbrs[0] > a->nbrs[1]){
	// 	sa(a);
	// 	ft_printf("SA\n");
	// 	actions++;
	// 	// print_stack(*a);
	// 	// print_stack(*b);
	// }
	// if (!sorted(*a)){
	// 	pb(a, b);
	// 	ft_printf("PB\n");
	// 	// print_stack(*a);
	// 	// print_stack(*b);
	// 	return (execute(a, b, actions+1));
	// }
	// else if (b->size > 1){
	// 	if (b->nbrs[0] < b->nbrs[1]){
	// 		sb(b);
	// 		ft_printf("SB\n");
	// 		actions++;
	// 		// print_stack(*a);
	// 		// print_stack(*b);
	// 	}
	// 	if (!sorted(*b)){
	// 		pa(a, b);
	// 		ft_printf("PA\n");
	// 		// print_stack(*a);
	// 		// print_stack(*b);
	// 		return (execute(a, b, actions+1));
	// 	}
	// } else if (b->size == 1){
	// 	pa(a, b);
	// 	ft_printf("PA\n");
	// 	actions++;
	// 	// print_stack(*a);
	// 	// print_stack(*b);
	// }
	// ft_printf("%d\n", actions);
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
