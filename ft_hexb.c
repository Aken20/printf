/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:27:21 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 20:22:52 by ahibrahi         ###   ########.fr       */
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

int	ft_hexb(unsigned long long x, int i)
{
	char	c;

	c = 0;
	if (x >= 16)
	{
		ft_hexb(x / 16, i);
		ft_hexb(x % 16, i);
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
			c = x - 10 + 'A';
			i += putchar((char)c);
		}
	}
	i = ft_xcount(x);
	return (i);
}