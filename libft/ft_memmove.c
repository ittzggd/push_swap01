/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:13:24 by hejang            #+#    #+#             */
/*   Updated: 2021/12/15 19:55:33 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *source, int size);

void	*ft_memmove(void *dest, const void *source, int size)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (dest == source)
		return (dst);
	if (dest < source)
	{
		while (size-- > 0)
			*dst++ = *src++;
	}
	else
	{
		dst += (size - 1);
		src += (size - 1);
		while (size-- > 0)
			*dst-- = *src--;
	}
	return (dest);
}
