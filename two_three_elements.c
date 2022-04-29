/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 01:06:45 by hejang            #+#    #+#             */
/*   Updated: 2022/04/30 01:06:55 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_two_elements(void)
{
	write(1, "sa\n", 3);
}

void	sort_three_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*curr;
	int				total;

	curr = stack_a->header_node.next;
	total = stack_a->current_element_count + stack_b->current_element_count;
	if (curr->index == total - 3)
	{
		first_case(stack_a, curr, total);
	}
	else if (curr->index == total - 2)
	{
		second_case(stack_a, curr, total);
	}
	else if (curr->index == total - 1)
	{
		third_case(stack_a, curr, total);
	}
}

void	first_case(t_stack *stack_a, t_stack_node *curr, int total)
{	
	curr = curr->next;
	if (curr->index == total - 1)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	second_case(t_stack *stack_a, t_stack_node *curr, int total)
{
	curr = curr->next;
	if (curr->index == total - 3)
		sa(stack_a);
	else
		rra(stack_a);
}

void	third_case(t_stack *stack_a, t_stack_node *curr, int total)
{
	curr = curr->next;
	if (curr->index == total - 3)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}
