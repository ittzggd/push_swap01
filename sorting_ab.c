/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:17 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 23:50:17 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_stack	*stack_a)
{
	t_stack_node	*curr;
	int				i;

	if (stack_a == NULL)
		return (-1);
	i = 0;
	curr = stack_a->header_node.next;
	while (i < stack_a->current_element_count)
	{
		if (i != curr->index)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

void	sort_stack(t_stack	*stack_a)
{
	int		num;
	int		chunk;
	t_stack	*stack_b;

	num = 0;
	stack_b = create_stack();
	if (stack_a->current_element_count <= 5)
		sort_less_than_five(stack_a, stack_b);
	chunk = get_chunk(stack_a->current_element_count);
	from_a_to_b(stack_a, stack_b, chunk);
	from_b_to_a(stack_a, stack_b);
	free(stack_b);
}

void	from_a_to_b(t_stack *stack_a, t_stack *stack_b, int chunk)
{
	int				num;
	t_stack_node	*head;
	t_stack_node	*top;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	num = 0;
	head = &stack_a->header_node;
	while (stack_a->current_element_count > 0)
	{
		top = head->next;
		if (top->index <= num)
		{
			pb(stack_a, stack_b);
			num++;
		}
		else if ((num < top->index) && (top->index <= num + chunk))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			num++;
		}
		else if (num + chunk < top->index)
			ra(stack_a);
	}
}

int	get_chunk(int element_count)
{
	int	chunk;
	int	x;

	if (element_count < 0)
		return (-1);
	x = element_count;
	chunk = (0.000000053 * x * x) + (0.03 * x) + 14.5;
	return (chunk);
}
