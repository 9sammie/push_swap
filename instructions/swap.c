/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:13:50 by maballet          #+#    #+#             */
/*   Updated: 2025/01/20 15:18:49 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_a(int **stack)
{
    int i;
	int	temp;

    i = start_of_stack(stack[0]);
	temp = 0;
	temp = stack[0][i];
	stack [0][i] = stack [0][i + 1];
	stack [0][i + 1] = temp;
}
