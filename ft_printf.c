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

static int ft_pset(const char *type, void a)
{
	if (type[i] == 'i' || type[i] == 'd')
		c += ft_putnbr((int)(a));
	else if (type[i] == 'u')
		c += ft_u((unsigned int)(a));
	else if (type[i] == 'c')
	{
		ft_putchar((int)(a));
		c++;
	}
	else if (type[i] == 's')
		c += ft_putstr((char *)(a));
	else if (type[i] == 'p')
		c += ft_p((unsigned long long)(a));
	else if (type[i] == 'x')
		c = ft_hex((unsigned long long)(a), c);
	else if (type[i] == 'X')
		c = ft_hexb((unsigned long long)(a), c);
	else if (type[i] == '%')
	{
		write (1, "%", 1);
		i++;
	}
	return (c);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		i;
	int		c;
	int		p;

	p = 0;
	c = 0;
	i = 0;
	va_start (args, type);
	{
		while (type[i])
		{
			if (type[i] == '%')
			{
				p++;
				i++;
				ft_pset(type[i], va_arg(args, (void)))
			}
			else 
			{
				write (1, &type[i], 1);
				i++;
			}
		}
	}
	va_end (args);
	return ((i + c) - p);
}

int	main(void)
{
	char	*s;
	int		i;

	s = "pip";
	i = printf("%x%xx%x", 1, 2, -3);
	printf("\n%i\n", i);
	i = ft_printf("%x%xx%x", 1, 2, -3);
	printf("\n%i\n", i);
	return (0);
}
