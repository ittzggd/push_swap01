/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:32 by hejang            #+#    #+#             */
/*   Updated: 2022/04/25 18:08:44 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_position(t_stack *stack)
{
	int				max;
	int				position;
	t_stack_node	*curr;

	if (stack == NULL || stack->current_element_count == 0)
		return (-1);
	position = 0;
	max = stack->current_element_count - 1;
	curr = stack->header_node.next;
	while (curr->index != max)
	{
		position++;
		curr = curr->next;
	}
	return (position);
}

void	from_b_to_a(t_stack	*stack_a, t_stack *stack_b)
{
	int				mid;
	int				max_position;

	while (stack_b->current_element_count > 0)
	{	
		max_position = get_max_position(stack_b);
		mid = (stack_b->current_element_count - 1) / 2;
		if (mid - max_position > 0)
		{
			while (max_position > 0)
			{
				rb(stack_b);
				max_position--;
			}
		}
		else
		{
			while (max_position < stack_b->current_element_count)
			{
				rrb(stack_b);
				max_position++;
			}
		}
		pa(stack_a, stack_b);
	}
}
