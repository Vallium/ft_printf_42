/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:37:26 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/09 14:37:28 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_write_u(t_options *opt, unsigned long long n)
{
	int		len;
	int		temp;

	temp = (n || opt->precise) ? ft_ulonglen(n) : 0;
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		ft_putnbrul(n);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	return ((opt->len > len) ? opt->len : len);
}

int				conv_u(t_options *opt, va_list *ap, int *ret)
{
	unsigned long long	n;

	if (1 << opt->modif & 30)
		n = va_arg(*ap, unsigned long);
	else if (opt->modif == 5)
		n = (unsigned char)va_arg(*ap, unsigned int);
	else
		n = va_arg(*ap, unsigned int);
	*ret += ft_write_u(opt, n);
	return (0);
}

int				conv_u2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 8;
	return (conv_u(opt, ap, ret));
}
