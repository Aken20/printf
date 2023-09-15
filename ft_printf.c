/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:11:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 20:35:42 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pset(const char type, unsigned long long a)
{
	int		c;

	c = 0;
	if (type == 'i' || type == 'd')
		c = ft_putnbr((int)(a));
	else if (type == 'u')
		c = ft_u((unsigned int)(a));
	else if (type == 'c')
		c = ft_putchar((int)(a));
	else if (type == 's')
		c = ft_putstr((char *)(a));
	else if (type == 'p')
		c = ft_p((unsigned long long)(a));
	else if (type == 'x')
		c += ft_hex((unsigned int)(a));
	else if (type == 'X')
		c += ft_hexb((unsigned int)(a));
	else if (type == '%')
		c += write (1, "%", 1);
	return (c);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (!type)
		return (0);
	va_start (args, type);
	{
		while (type[i])
		{
			if (type[i] == '%')
			{
				i++;
				c += ft_pset(type[i++], va_arg(args, unsigned long long));
			}
			else 
				c += write (1, &type[i++], 1);
		}
	}
	va_end (args);
	return (c);
}

// int	main(void)
// {
// 	char	*s;
// 	int		i;

// 	s = "pip";
// 	i = printf(" %%%x ", 767);
// 	printf("\n%i\n", i);
// 	i = ft_printf(" %%%x ", 767);
// 	printf("\n%i\n", i);
// 	return (0);
// }
