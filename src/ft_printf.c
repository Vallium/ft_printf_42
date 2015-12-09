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
#include "libft.h"

#include "printf.h"

static int		ft_parse_var(char *str, t_vars *vars)
{
	int			i;

	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || ft_strchr(FT_PARSE, str[i])))
		i++;
	if (str[i])
	{
		ft_parse(str, i, vars);
		i++;
	}
	return (i);
}

static void		ft_init_functions_tab(int (**f)(t_options *, va_list *, int *))
{
	f[0] = conv_s;
	f[1] = conv_s2;
	f[2] = conv_p;
	f[3] = conv_d;
	f[4] = conv_d2;
	f[5] = conv_d;
	f[6] = conv_o;
	f[7] = conv_o2;
	f[8] = conv_u;
	f[9] = conv_u2;
	f[10] = conv_x;
	f[11] = conv_x2;
	f[12] = conv_c;
	f[13] = conv_c2;
	(void)f[14]; // = ft_b;
	(void)f[15]; // = ft_r;
	(void)f[16]; // = ft_g;
}

static int		ft_sub_printf(char *str, t_vars *vars)
{
	char		*beg_ptr;

	beg_ptr = str;
	vars->ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			vars->ret += str - beg_ptr;
			if (vars->ret > 0)
				write(1, beg_ptr, str - beg_ptr);
			str += ft_parse_var(str + 1, vars) + 1;
			if (vars->ret == -1)
				return (-1);
			beg_ptr = str;
		}
		else
			str++;
	}
	vars->ret += ft_strlen(beg_ptr);
	ft_putstr(beg_ptr);
	va_end(vars->ap);
	return (0);
}

int				ft_printf(const char *str, ...)
{
	t_vars		vars;
	int			ret;

	if (str == NULL)
		return (-1);
	va_start(vars.ap, str);
	ft_init_functions_tab(vars.f);
	ret = ft_sub_printf((char*)str, &vars) != -1 ? vars.ret : -1;
	return (ret);
}
