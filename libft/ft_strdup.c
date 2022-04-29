/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:56:34 by hejang            #+#    #+#             */
/*   Updated: 2021/12/13 01:28:46 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = ft_strlen(str);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (0);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}	
