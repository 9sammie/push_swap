/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:01:43 by maballet          #+#    #+#             */
/*   Updated: 2025/01/20 16:15:41 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_count(int *stack, int argc)
{
    int i;

    i = 0;
    while (stack[argc - 2 - i])
        i++;
    return (i);
}

int start_of_stack(int *stack, int argc)
{
    int i;

    i = argc - 2;
    while (stack[i] != '\0')
        i--;
    i++;
    return (i);
}
