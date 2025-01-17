/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:33:12 by maballet          #+#    #+#             */
/*   Updated: 2025/01/17 18:45:15 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		int_checker(int *tab_a)
{
	int	i;
	int	j;

	i = 0;
	while (tab_a[i])
	{
		j = i + 1;
		while (tab_a[j])
		{
			if (tab_a[i] == tab_a[j])
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
