/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:14:42 by hejang            #+#    #+#             */
/*   Updated: 2021/12/17 13:16:42 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
		return ;
	}
}
