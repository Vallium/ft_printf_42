/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:40:05 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/17 13:40:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + '0');
		}
	}
}

int			print_char(va_list flags)
{
	char	c;

	c = va_arg(flags, int);
	ft_putchar(c);
	return (1);
}

int			print_str(va_list flags)
{
	char	*str;

	str = va_arg(flags, char *);
	ft_putstr(str);
	return (1);
}

int			print_int(va_list flags)
{
	int		d;

	d = va_arg(flags, int);
	ft_putnbr(d);
	return (1);
}

int			choose_flag(va_list flags, char c)
{
	if (c == 'c')
		print_char(flags);
	else if (c == 's')
		print_str(flags);
	else if (c == 'd')
		print_int(flags);
	else if (c == '%')
		ft_putchar(c);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list		flags;

	va_start(flags, str);
	while(*str)
	{
		if(*str == '%')
		{
			str++;
			choose_flag(flags, *str);
		}
		else if (*str != '%')
			ft_putchar(*str);
		str++;
	}
	va_end(flags);
	return (0);
}
