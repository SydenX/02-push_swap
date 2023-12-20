/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:05:54 by jtollena          #+#    #+#             */
/*   Updated: 2023/12/20 13:56:37 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(0);
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
	while (stack.nbrs[i] != 0)
	{
		j = 0;
		k = 0;
		while (stack.nbrs[j] != 0)
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

void	create_stacks(char **argv, int size)
{
	int		i;
	t_stack stack_a;
	t_stack stack_b;

	stack_a.nbrs = malloc((size) * sizeof(int));
	stack_b.nbrs = malloc((size) * sizeof(int));

	i = 0;
	while (i < size - 1)
	{
		stack_a.nbrs[i] = ft_atoi(argv[i]);
		i++;
	}
	stack_a.nbrs[i] = 0;
	if (duplicated(stack_a))
		error("Do not put duplicated numbers.");
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
