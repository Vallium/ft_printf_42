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

int				ft_precise(char *str, int len, va_list *ap)
{
	int		i;
	int		n;

	if ((i = ft_searchpoint(str, len - 1)) == -1)
		return (-1);
	n = (str[i + 1] == '*') ? va_arg(*ap, int) : ft_atoi(str + i + 1);
	return ((n >= 0) ? n : -1);
}

int				ft_modif(char *s1, int len)
{
	int		j;
	char	*s2;
	int		modif;

	j = -1;
	s1 += len - 1;
	while (++j < len)
	{
		s2 = FT_MODIF;
		while (*s2)
		{
			if (*s1 == *s2)
			{
				modif = s2 - FT_MODIF;
				if (*s2 == 'l' && *(s1 - 1) == 'l')
					modif = 4;
				else if (*s2 == 'h' && *(s1 - 1) == 'h')
					modif = 5;
				return (modif);
			}
			s2++;
		}
		s1--;
	}
	return (-1);
}

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
