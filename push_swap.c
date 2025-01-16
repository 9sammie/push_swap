/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/01/16 17:27:20 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   **push_swap(char **numbers, int argc)
{
	int	i;
	int	**pile;

	i = 0;
	pile[0] = malloc(sizeof(int*) * (argc - 1));
	pile[1] = malloc(sizeof(int*) * (argc - 1));
	while (numbers[i + 1] != NULL)
	{
		pile[0][i] = ft_atoi(numbers[i + 1]);
		i++;
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
	result = push_swap(argv, argc);
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
