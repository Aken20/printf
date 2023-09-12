/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:15:30 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 20:25:49 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(unsigned long long p)
{
	int	i;

	i = 0;
	if (p == 0x0)
	{
		i += ft_putchar('0');
		return (i);
	}
	i += ft_putstr("0x");
	i += ft_hex(p, i);
	return (i);
}
