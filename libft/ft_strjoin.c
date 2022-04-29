/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:45:34 by hejang            #+#    #+#             */
/*   Updated: 2021/12/13 23:56:27 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcat(new_str + len1, s2, len2 + 1);
	return (new_str);
}
