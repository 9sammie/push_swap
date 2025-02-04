/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:31 by maballet          #+#    #+#             */
/*   Updated: 2025/02/03 11:19:23 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheapest(t_stack *a, t_stack *b, int cheapest)
{
	int	i;
	int closest;

	i = 0;
	closest = find_closest_sup(b->array[cheapest], a);
	if (cheapest <= b->length / 2 && closest <= a->length / 2)
		option_01(a, b, cheapest, closest);
	else if (cheapest > b->length / 2 && closest > a->length / 2)
		option_02(a, b, cheapest, closest);
	else if (cheapest <= b->length / 2 && closest > a->length / 2)
		option_03(a, b, cheapest, closest);
	else
		option_04(a, b, cheapest, closest);
}

void	option_01(t_stack *a, t_stack *b, int cheapest, int closest)
{
	while (cheapest > 0 && closest > 0)
		{
			rotate(b, a, "rr");
			cheapest--;
			closest--;
		}
		while (cheapest > 0)
		{
			rotate(b, NULL, "rb");
			cheapest--;
		}
		while (closest > 0)
		{
			rotate(a, NULL, "ra");
			closest--;
		}
		push(a, b, "pa");
}

void	option_02(t_stack *a, t_stack *b, int cheapest, int closest)
{
	cheapest = b->length - cheapest;
		closest = a->length - closest;
		while (cheapest > 0 && closest > 0)
		{
			reverse_rotate(b, a, "rrr");
			cheapest--;
			closest--;
		}
		while (cheapest > 0)
		{
			reverse_rotate(b, NULL, "rrb");
			cheapest--;
		}
		while (closest > 0)
		{
			reverse_rotate(a, NULL, "rra");
			closest--;
		}
		push(a, b, "pa");
}

void	option_03(t_stack *a, t_stack *b, int cheapest, int closest)
{
	closest = a->length - closest;
		while (cheapest > 0)
		{
			rotate(b, NULL, "rb");
			cheapest--;
		}
		while (closest > 0)
		{
			reverse_rotate(a, NULL, "rra");
			closest--;
		}
		push(a, b, "pa");
}

void	option_04(t_stack *a, t_stack *b, int cheapest, int closest)
{
	cheapest = b->length - cheapest;
		while (cheapest > 0)
		{
			reverse_rotate(b, NULL, "rrb");
			cheapest--;
		}
		while (closest > 0)
		{
			rotate(a, NULL, "ra");
			closest--;
		}
		push(a, b, "pa");
}