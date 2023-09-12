/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:11:04 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 16:06:39 by ahibrahi         ###   ########.fr       */
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
				else if (type[i] == '%')
				{
					write (1, "%", 1);
					i++;
				}
			}
			else 
				write (1, &type[i++], 1);
		}
		--i;
	}
	va_end (args);
	return ((i + c) - p + 1);
}

// int	main(void)
// {
// 	char	*s;
// 	int		i;

// 	s = 0;
// 	i = printf(" %u  %u %u", 0, -16, 10);
// 	printf("\n%i\n", i);
// 	i = ft_printf(" %u  %u %u", 0, -16, 10);
// 	printf("\n%i\n", i);
// 	return (0);
// }
