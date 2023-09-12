/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 07:13:36 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/09/12 16:07:33 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *type, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_u(unsigned int n);
int		ft_itoa(long long n);

#endif
