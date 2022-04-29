/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:00:04 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 23:53:42 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		ft_error();
	new_stack->current_element_count = 0;
	new_stack->header_node.next = NULL;
	new_stack->header_node.prev = NULL;
	return (new_stack);
}

void	push_stack_a(t_stack *stack_a, t_stack_node element)
{
	t_stack_node	*curr;
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		ft_error();
	*new = element;
	new->next = new;
	new->prev = new;
	curr = stack_a->header_node.prev;
	if (stack_a->current_element_count == 0)
		stack_a->header_node.next = new;
	else
	{
		new->next = curr->next;
		new->prev = curr;
		curr->next->prev = new;
		curr->next = new;
	}
	stack_a->header_node.prev = new;
	stack_a->current_element_count++;
}
