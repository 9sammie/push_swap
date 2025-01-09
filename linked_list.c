/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:36:18 by maballet          #+#    #+#             */
/*   Updated: 2025/01/09 17:42:38 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack   stack_init(char **argv)
{
	stack	*temp;
	stack	*pile;
	int i;

	pile = NULL;
	temp = NULL;
	i = 0;
	while (argv[i])
	{
		temp = new_node(ps_atoi(argv[i]));
		if (!temp)
		{
			ps_lstclear(pile, del());
			ft_printf("Error\n");
			return(*pile);
		}
        pile_addback(pile, temp);
        i++;
	}
	return(*pile);
}

stack	*new_node(void *number)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if (!new)
		return (NULL);
	new->content = number;
	new->next = NULL;
	return (new);
}

void	pile_addback(stack **current_pile, stack *new)
{
	stack	*temp;

	temp = *current_pile;
	if (!current_pile || !new)
		return ;
	if (!*current_pile)
	{
		*current_pile = new ;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void	ps_lstclear(stack **lst, void (*del)(void *))
{
	stack	*temp;
	stack	*getnext;

	temp = *lst;
	while (temp)
	{
		getnext = temp->next;
		del(temp->content);
		free(temp);
		temp = getnext;
	}
	*lst = NULL;
}