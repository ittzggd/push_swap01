/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:15:59 by hejang            #+#    #+#             */
/*   Updated: 2021/12/15 01:06:20 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	int		i;
	int		j;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= d_len)
		return (s_len + size);
	else if (size > d_len)
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0' && (size_t)j < (size - d_len - 1))
		{
			dest[j + i] = src[j];
			j++;
		}
	}
	dest[j + i] = '\0';
	return (s_len + d_len);
}
