/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/01/17 18:34:54 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(int **pile)
{
	free(pile[0]);
	free(pile[1]);
	free(pile);
}

int		**push_swap(char **numbers, int argc)
{
	int	i;
	int	**pile;

	i = 0;
	pile = malloc(sizeof(int*) * 3);
	pile[0] = malloc(sizeof(int) * (argc));
	pile[1] = malloc(sizeof(int) * (argc));
	if (!(pile[0]) || !(pile[1]))
	{
		ft_printf("Error");
		free_tab(pile);
		return (pile);
	}
	while (numbers[i + 1] != NULL)
	{
		if (ft_atol(numbers[i + 1]) > 2147483647 ||
				ft_atol(numbers[i + 1]) < -2147483648)
		{
			ft_printf("Error\n");
			free_tab(pile);
			return (pile);
		}
		pile[0][i] = ft_atoi(numbers[i + 1]);
		i++;
	}
	if (int_checker(pile[0]) == 1)
	{
		free_tab(pile);
		return (pile);
	}
	return(pile);
}

int    main(int argc, char **argv)
{
	int	**result;     // 1 tab of tab for each stack.
	int	i;
	int j;

	j = 0;
	i = 0;
	if (char_checker(argv) == 1)
		return (0);
	result = push_swap(argv, argc);
	if (result[0] == NULL)
		return(0);
	while (result[i][j])
	{
		j = 0;
		if (i == 0)
			ft_printf("A\n-\n");
		while(result[i][j])
		{
			ft_printf("%d\n", result[i][j]);
			j++;
		}
		i++;
		if (i == 1)
			ft_printf("\nB\n-\n");
	}
	return(0);
}
