/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/02/05 18:17:24 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stack
{
	int	length;
	int	*array;
}				t_stack;

int		push_swap(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc);
int		int_doublechecker(t_stack *stack_a, int argc);
int		char_checker(char **argv);
int		int_overflowchecker(t_stack *stack_a, char **numbers);
void	stack_push(t_stack *dest, int val);
int		stack_pop(t_stack *stack);
int		stack_shift(t_stack *stack);
void	stack_unshift(t_stack *stack, int val);
void	swap(t_stack *s1, t_stack *s2, char *instruct);
void	push(t_stack *dest, t_stack *src, char *instruct);
void	rotate(t_stack *s1, t_stack *s2, char *instruct);
void	reverse_rotate(t_stack *s1, t_stack *s2, char *instruct);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		sort_check(t_stack *stack);
void	sort_3(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
int		find_closest_inf(int nbr, t_stack *stack);
int		find_closest_sup(int nbr, t_stack *stack);
int		find_median(t_stack *a);
void	median_sort(t_stack *a, t_stack *b);
void	max_on_top(t_stack *stack);
void	min_on_top(t_stack *stack);
int		check_rotate(int nbr, t_stack *stack);
void	cpy_sort(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest);
void	option_01(t_stack *a, t_stack *b, int cheapest, int closest);
void	option_02(t_stack *a, t_stack *b, int cheapest, int closest);
void	option_03(t_stack *a, t_stack *b, int cheapest, int closest);
void	option_04(t_stack *a, t_stack *b, int cheapest, int closest);
int		find_cheapest(t_stack *stack_a, t_stack *stack_b);
int		count_cost_01(t_stack *dest, int *index_of_closest, int *i);
int		count_cost_02(t_stack *dest, t_stack *src, int *index_of_closest, int *i);

#endif