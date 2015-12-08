/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 20:21:44 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/08 20:21:47 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_dectohex(char *hex, unsigned long n, int up)
{
	int		i;
	long	rem;

	i = 0;
	if (!n)
		hex[i++] = '0';
	while (n)
	{
		rem = n % 16;
		if (rem >= 10 && rem <= 15)
			hex[i] = (up) ? ft_toupper(FT_HEX[rem % 10]) : FT_HEX[rem % 10];
		else
			hex[i] = rem + '0';
		++i;
		n /= 16;
	}
	hex[i] = '\0';
	if (i > 1)
		ft_strrev(hex);
	return (0);
}

static int		ft_write_p(t_options *opt, char *hex, unsigned long n)
{
	int		len;
	int		temp;

	if (opt->len)
		opt->len -= 2;
	if (opt->precise == -1 && opt->zero)
		opt->precise = opt->len;
	temp = (n || opt->precise) ? ft_strlen(hex) : 0;
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, "0x", 2);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		write(1, hex, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len > len) ? opt->len : len;
	return (len + 2);
}

int				conv_p(t_options *opt, va_list *ap, int *ret)
{
	unsigned long	n;
	char			hex[20];

	n = va_arg(*ap, unsigned long);
	ft_dectohex(hex, n, 0);
	*ret += ft_write_p(opt, hex, n);
	return (0);
}
