/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:49:50 by hejang            #+#    #+#             */
/*   Updated: 2021/12/13 23:44:42 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	len = 0;
	if (!s || !f)
		return (0);
	while (s[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		if (!str[i])
			return (0);
		i++;
	}
	str[i] = '\0';
	return (str);
}
