/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:05 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 10:57:33 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	reverse_rotate(t_stack	*stack)
{
	t_stack_node	*head;
	t_stack_node	*bottom;

	if (stack == NULL)
		return (-1);
	if (stack->current_element_count < 2)
		return (0);
	head = &stack->header_node;
	bottom = head->prev;
	head->next = bottom;
	head->prev = bottom->prev;
	return (1);
}

void	rra(t_stack	*stack_a)
{
	if (stack_a == NULL)
		return ;
	if (reverse_rotate(stack_a) == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack	*stack_b)
{
	if (stack_b == NULL)
		return ;
	if (reverse_rotate(stack_b) == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack	*stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (reverse_rotate(stack_a) == 1 || reverse_rotate(stack_b) == 1)
		write(1, "rrr\n", 4);
}
