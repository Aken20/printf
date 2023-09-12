/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:42:44 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 20:21:57 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int	ft_xcount(unsigned long long x)
{
	int	len;

	len = 0;
	if (x <= 0)
		len++;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

int	ft_hex(unsigned long long x, int i)
{
	char	c;

	c = 0;
	if (x >= 16)
	{
		ft_hex(x / 16, i);
		ft_hex(x % 16, i);
	}
	else
	{
		if (x <= 9)
		{
			c = x + '0';
			i += putchar((char)c);
		}
		else
		{
			c = x - 10 + 'a';
			i += putchar((char)c);
		}
	}
	i = ft_xcount(x);
	return (i);
}
