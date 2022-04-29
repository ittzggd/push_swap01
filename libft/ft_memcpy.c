/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:46:24 by hejang            #+#    #+#             */
/*   Updated: 2021/12/15 20:05:02 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *source, int num);

void	*ft_memcpy(void *dest, const void *source, int num)
{
	unsigned char	*tmp;
	unsigned char	*src;
	int				i;

	tmp = (unsigned char *)dest;
	src = (unsigned char *)source;
	i = 0;
	if (dest == source)
		return (dest);
	while (i < num)
	{
		tmp[i] = src[i];
		i++;
	}
	return (dest);
}
