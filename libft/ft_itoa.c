/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:47:26 by hejang            #+#    #+#             */
/*   Updated: 2021/12/17 02:12:28 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_itoa(int n);
int		getlen(int n);
char	*make_a(char *str, int n, int i, int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = getlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	str = make_a(str, n, i, len);
	str[len] = '\0';
	return (str);
}

int	getlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*make_a(char *str, int n, int i, int len)
{
	while (len > i)
	{
		len--;
		if (n < 0)
		{
			str[len] = '0' + (n % 10) * (-1);
			n = n / 10;
		}
		else
		{
			str[len] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (str);
}
