/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:38:08 by hejang            #+#    #+#             */
/*   Updated: 2021/12/13 14:49:43 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *));

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !*lst || !del)
		return ;
	while ((*lst))
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
