/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:25:31 by aalliot           #+#    #+#             */
/*   Updated: 2015/11/25 17:25:38 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_notype(char *str, t_options *opt)
{
	int		len;

	len = (opt->len > 1) ? opt->len : 1;
	opt->type = 0;
	if (!(opt->flags & 1))
		ft_putspace(opt, 1, 0);
	write(1, str, 1);
	if (opt->flags & 1)
		ft_putspace(opt, 1, 0);
	return (len);
}

void			ft_parse(char *str, int len, t_vars *vars)
{
	t_options	opt;
	char		*c;
	int			(**pf)(t_options *, va_list *, int *);

	opt.flags = ft_flag(FT_FLAGS, str, len);
	opt.len = ft_len(str, len, &vars->ap);
	opt.flags |= (opt.len >= 0) ? 0 : 1;
	opt.len = (opt.len >= 0) ? opt.len : -opt.len;
	opt.precise = ft_precise(str, len, &vars->ap);
	opt.modif = ft_modif(str, len);
	opt.zero = ft_zero(str);
	if ((c = ft_strchr(FT_TYPES, str[len])))
	{
		pf = vars->f;
		opt.type = c - FT_TYPES;
		if (((*pf[opt.type])(&opt, &vars->ap, &vars->ret)) == -1)
			vars->ret = -1;
	}
	else
		vars->ret += ft_notype(str + len, &opt);
}