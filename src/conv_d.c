/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:52:04 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/08 15:52:06 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_write_d(t_options *opt, long long n)
{
	int		len;
	int		temp;
	int		issigned;

	issigned = (n < 0 || opt->flags & 6) ? 1 : 0;
	if (opt->precise == -1 && opt->zero && issigned)
	{
		--opt->len;
		opt->precise = opt->len;
	}
	temp = ft_nbrlen2((n < 0) ? -n : n);
	temp = (n || opt->precise) ? temp : 0;
	len = ((opt->precise > temp) ? opt->precise : temp) + issigned;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, n);
	if (issigned)
		ft_putsigned(opt->flags, n);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		ft_putnbrul((n < 0) ? -n : n);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, n);
	return ((opt->len > len) ? opt->len : len);
}

int			ft_d(t_options *opt, va_list *ap, int *ret)
{
	long long	n;

	if (opt->type == 5)
		opt->type = 3;
	if (1 << opt->modif & 30)
		n = va_arg(*ap, long);
	else if (opt->modif == 5)
		n = (char)va_arg(*ap, int);
	else
		n = va_arg(*ap, int);
	*ret += ft_write_d(opt, n);
	return (0);
}

int			ft_d2(t_options *opt, va_list *ap, int *ret)
{
	opt->modif = 1;
	opt->type = 3;
	return (ft_d(opt, ap, ret));
}
