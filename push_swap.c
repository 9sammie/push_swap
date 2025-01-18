/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/01/18 18:43:52 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		**push_swap(char **numbers, int argc)
{
	int	i;
	int	**pile;

	i = 0;
	pile = init(numbers, argc);
	if (!(pile))
		return NULL;
	return (pile);
}

int    main(int argc, char **argv)
{
	int	**result;     // 1 tab of tab for each stack.
	int	i;

	i = 0;
	if (argc < 2 || char_checker(argv) == 1)
		return (0);
	result = push_swap(argv, argc);
	if (!(result))
		return(0);
	
	while(i < argc - 1)
	{
		ft_printf("%d\n", result[0][i]);
		i++;
	}
	ft_printf("-\na\n\n");
	i = 0;
	while(i < argc - 1)
	{
		ft_printf("%d\n", result[1][i]);
		i++;
	}
	ft_printf("-\nb\n\n");
	free_stacks(result);
	return(0);
}
