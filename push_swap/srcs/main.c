/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:54 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/09 15:16:28 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	error(int n)
{
	ft_printf("Error\n");
	exit(0);
}

void	setup_onearg(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < ft_strlen(arg))
	{
		if (ft_atoi(&arg[i]) > 2147483647 || ft_atoi(&arg[i]) < -2147483648)
			return (free(stack_a->nbrs), free(stack_b->nbrs), error(10));
		stack_a->nbrs[j++] = ft_atoi(&arg[i]);
		while (arg[i] != ' ' && arg[i] != 0)
		{
			if ((arg[i] >= '0' && arg[i] <= '9') 
				|| (arg[i] == '-' && (arg[i + 1] >= '0' && arg[i + 1] <= '9')))
				i++;
			else
				return (free(stack_a->nbrs), free(stack_b->nbrs), error(3));
		}
		i++;
	}
	stack_a->size = j;
}

void	setup_stacks(t_stack *stack_a, t_stack *stack_b, char **argv, int size)
{
	int	i;

	i = 0;
	if (get_int_in_str(argv[1]) >= 2 && size == -1)
		setup_onearg(argv[1], stack_a, stack_b);
	else
	{
		while (i < size - 1)
		{
			if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648
				|| ft_strlen(argv[i]) > 13)
				return (free(stack_a->nbrs), free(stack_b->nbrs), error(10));
			stack_a->nbrs[i] = ft_atoi(argv[i]);
			i++;
		}
		stack_a->size = i;
	}
	stack_b->size = 0;
	if (duplicated(*stack_a))
		return (free(stack_a->nbrs), free(stack_b->nbrs), error(1));
	if (sorted(*stack_a))
		return (free(stack_a->nbrs), free(stack_b->nbrs), error(2));
}

void	create_stacks(char **argv, int size, int type)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.nbrs = malloc((size - 1) * sizeof(int));
	if (stack_a.nbrs == NULL)
		return ;
	stack_b.nbrs = malloc((size - 1) * sizeof(int));
	if (stack_b.nbrs == NULL)
		return (free(stack_a.nbrs));
	if (type == -1)
		size = -1;
	setup_stacks(&stack_a, &stack_b, argv, size);
	if (stack_a.size == 2)
		sa(&stack_a, 0);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		execute(&stack_a, &stack_b);
	return (free(stack_a.nbrs), free(stack_b.nbrs));
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (get_int_in_str(argv[1]) >= 2)
			create_stacks(argv, get_int_in_str(argv[1]) + 1, -1);
		else
			return (error(6), 0);
	}
	else if (!are_int(argv, argc))
		return (error(7), 0);
	else if (argc > 2)
		create_stacks(&argv[1], argc, 1);
	return (1);
}
