/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:17:17 by hejang            #+#    #+#             */
/*   Updated: 2021/12/17 14:07:52 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*first;

	if (!lst || !f)
		return (0);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (0);
	list = first;
	while (lst->next)
	{
		lst = lst->next;
		list->next = ft_lstnew(f(lst->content));
		if (!(list->next))
		{
			ft_lstclear(&first, del);
			return (0);
		}
		list = list->next;
	}
	return (first);
}
