/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/18 18:57:33 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"

int		**push_swap(char **numbers, int argc);
int		int_doublechecker(int *stack_a);
int		char_checker(char **argv);
int     **init(char **numbers, int argc);
int		**int_atolchecker(char **numbers, int argc);
void	free_stacks(int **stack);
void    push_a(int **stack);

#endif