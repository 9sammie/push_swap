/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/01/09 17:40:46 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack   **push_swap(char **number)
{
	stack	**piles;
	stack	pile_a;
	
	pile_a = stack_init(number);
	piles[0][0] = pile_a;
	return(piles);
}

void    main(int argc, char **argv)
{
	int	**result;     // 1 tab of tab for each stack.
	int	i;
	int	j;

	j = 0;
	result = push_swap(argv);
	while (result[j][i])
	{
		i = 0;
		if (i == 0 && j == 1)
			ft_printf("A\n_\n");
		while (result[j][i])
		{
			ft_printf("%d\n", result[j][i]);
			i++;
		}
		j++;
		if (i == 0 && j == 2)
			ft_printf("B\n_\n");
	}
	return(0);
}

int	ps_atoi(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
