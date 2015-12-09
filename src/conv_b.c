/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:25:08 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/09 15:25:11 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_dectobin(char *bin, long n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		bin[i++] = (n & 1) + '0';
		n >>= 1;
	}
	bin[i] = '\0';
	if (i > 1)
		ft_strrev(bin);
	return (0);
}

static int		ft_write_b(t_options *opt, char *bin, long n)
{
	int		len;
	int		temp;

	temp = (n || opt->precise) ? ft_strlen(bin) : 0;
	len = ((opt->precise > temp) ? opt->precise : temp);
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	if (opt->precise > temp)
		ft_putzero(opt, temp);
	if (opt->precise || n)
		write(1, bin, temp);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	return ((opt->len > len) ? opt->len : len);
}

int				conv_b(t_options *opt, va_list *ap, int *ret)
{
	long	n;
	char	bin[50];

	if (1 << opt->modif & 30)
		n = va_arg(*ap, long);
	else if (!opt->modif)
		n = (short)va_arg(*ap, int);
	else if (opt->modif == 5)
		n = (char)va_arg(*ap, int);
	else
		n = va_arg(*ap, int);
	n = ft_dectobin(bin, n);
	*ret += ft_write_b(opt, bin, n);
	return (0);
}
