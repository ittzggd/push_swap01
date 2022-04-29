/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:57 by hejang            #+#    #+#             */
/*   Updated: 2022/04/30 05:23:11 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include"push_swap.h"

void	change_arg(int argc, char **argv, t_stack *stack_a)
{
	int				i;
	int				j;
	char			**s_num;
	t_stack_node	new_node;

	i = 1;
	while (i < argc)
	{
		j = 0;
		s_num = ft_split(argv[i], 32);
		if (*s_num == NULL)
			ft_error();
		while (s_num[j] != NULL)
		{
			reset_node(&new_node, s_num[j]);
			push_stack_a(stack_a, new_node);
			indexing_stack_a(stack_a);
			free(s_num[j]);
			j++;
		}
		free(s_num);
		i++;
	}
}

void	reset_node(t_stack_node *new_node, char *str)
{
	int	num;

	num = ft_atoi(str);
	new_node->index = 0;
	new_node->data = num;
	new_node->prev = NULL;
	new_node->next = NULL;
}

void	indexing_stack_a(t_stack *stack_a)
{
	int				i;
	t_stack_node	*head;
	t_stack_node	*new_node;
	t_stack_node	*curr;

	head = &stack_a->header_node;
	new_node = head->prev;
	curr = head->next;
	i = 0;
	while (i < stack_a->current_element_count - 1)
	{
		if (new_node->data == curr->data)
			ft_error();
		else if (new_node->data > curr->data)
			new_node->index++;
		else if (new_node->data < curr->data)
			curr->index++;
		curr = curr->next;
		i++;
	}
}
