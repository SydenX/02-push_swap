/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:24:06 by jtollena          #+#    #+#             */
/*   Updated: 2024/01/10 12:24:59 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	get_int_in_str(char *str)
{
	int		size;
	size_t	i;

	i = 0;
	size = 1;
	while (i < ft_strlen(str))
	{
		while (str[i] != ' ' && str[i] != 0)
			i++;
		if (str[i++] != 0)
			size++;
	}
	return (size);
}

void	print_stack(t_stack s)
{
	int	i;

	i = 0;
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
		if (argv[i][0] == '-' && (argv[i][1] < '0' || argv[i][1] > '9'))
			return (0);
		else if (argv[i][0] == '-')
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
