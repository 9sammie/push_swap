/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/18 18:43:29 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     **init(char **numbers, int argc)
{
    int **pile;

    pile = int_atolchecker(numbers, argc);
	if (!(pile))
		return NULL;
	if (int_doublechecker(pile[0]) == 1)
	{
		free_stacks(pile);
		return NULL;
	}
	return(pile);
}

void	free_stacks(int **stack)
{
	free(stack[0]);
	free(stack[1]);
	free(stack);
}

int		char_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!(argv))
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		int_doublechecker(int *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (stack_a[i])
	{
		j = i;
		while (stack_a[j])
		{
			if (stack_a[i] == stack_a[j] && i!=j)
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		**int_atolchecker(char **numbers, int argc)
{
	int	**pile;
	int	i;
	long	check;

	i = 0;
	if (!(pile = malloc(sizeof(int*) * 3)) ||
		!(pile[0] = ft_calloc(argc, sizeof(int))) ||
		!(pile[1] = ft_calloc(argc, sizeof(int))))
	{
		ft_printf("Error");
		free_stacks(pile);
		return NULL;
	}
	pile[2] = NULL;
	while (numbers[i + 1] != NULL)
	{
		if ((check = ft_atol(numbers[i + 1])) > 2147483647 || check < -2147483648)
		{
			ft_printf("Error\n");
			free_stacks(pile);
			return NULL;
		}
		pile[0][i++] = check;
	}
	return (pile);
}
