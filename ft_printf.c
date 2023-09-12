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
				if (type[i] == 'i' || type[i] == 'd')
				{
					c += ft_putnbr(va_arg (args, int));
					i++;
					p++;
				}
				else if (type[i] == 'u')
				{
					c += ft_u(va_arg (args, unsigned int));
					i++;
					p++;
				}
				else if (type[i] == 'c')
				{
					ft_putchar(va_arg (args, int));
					i++;
				}
				else if (type[i] == 's')
				{
					c += ft_putstr(va_arg (args, char *));
					p++;
					i++;
				}
				else if (type[i] == 'p')
				{
					c += ft_p(va_arg (args, unsigned long long));
					p++;
					i++;
				}
				else if (type[i] == 'x')
				{
					c = ft_hex(va_arg (args, unsigned long long), c);
					p++;
					i++;
				}
				else if (type[i] == 'X')
				{
					c = ft_hexb(va_arg (args, unsigned long long), c);
					p++;
					i++;
				}
				else if (type[i] == '%')
				{
					write (1, "%", 1);
					i++;
				}
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
