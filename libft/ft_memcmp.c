/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:35:26 by hejang            #+#    #+#             */
/*   Updated: 2021/12/09 13:05:35 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (i < size)
	{
		if (ptr[i] != ptr2[i])
			return (ptr[i] - ptr2[i]);
		i++;
	}
	return (0);
}
