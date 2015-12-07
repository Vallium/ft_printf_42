/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:15:10 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/07 16:15:28 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_s_bis(t_options *opt, char *s)
{
	int		len;

	len = ft_strlen(s);
	len = (opt->precise != -1 && len > opt->precise) ? opt->precise : len;
	if (opt->len > len && !(opt->flags & 1))
		ft_putspace(opt, len, 0);
	write(1, s, len);
	if (opt->len > len && opt->flags & 1)
		ft_putspace(opt, len, 0);
	len = (opt->len != -1 && len < opt->len) ? opt->len : len;
	return (len);
}

int			conv_s(t_options *opt, va_list *ap, int *ret)
{
	wchar_t		*s;
	char		*s2;
	int			value;

	s = NULL;
	s2 = NULL;
	if (opt->modif == 1)
	{
		// if ((s = va_arg(*ap, wchar_t *)))
		// 	value = ft_write_s(opt, s);
	}
	else
	{
		if ((s2 = va_arg(*ap, char *)))
			value = ft_write_s_bis(opt, s2);
	}
	if (!s && !s2)
	{
		s2 = ft_strdup("(null)");
		value = ft_write_s_bis(opt, s2);
		free(s2);
	}
	*ret += value;
	return (value);
}
