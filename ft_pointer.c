/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:15:30 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/17 00:44:42 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_xcount(unsigned long long int x)
{
	int	len;

	len = 0;
	if (x == 0)
		len++;
	while (x >= 16)
	{
		x /= 16;
		len++;
	}
	return (len);
}

static	int	ft_hexp(unsigned long long int x)
{
	int		c;
	int		i;
	char	*s;

	i = ft_xcount(x) + 1;
	if (x == 0)
		return (ft_putstr("0"));
	s = (char *)malloc(i + 1);
	if (!s)
		return (0);
	s[i--] = 0;
	while (x != 0)
	{
		c = x % 16;
		if (c <= 9)
			s[i--] = c + 48;
		else if (c <= 16)
			s[i--] = c + 87;
		x /= 16;
	}
	i = ft_putstr(s);
	free (s);
	return (i);
}

int	ft_pointer(unsigned long long p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (p == 0x0)
	{
		i += ft_putchar('0');
		return (i);
	}
	i += ft_hexp(p);
	return (i);
}
