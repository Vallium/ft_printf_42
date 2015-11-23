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

static void		ft_init_functions_tab(int (**f)(t_options *, va_list *, int *))
{
	f[0] = ft_s;
	f[1] = ft_s2;
	f[2] = ft_p;
	f[3] = ft_d;
	f[4] = ft_d2;
	f[5] = ft_d;
	f[6] = ft_o;
	f[7] = ft_o2;
	f[8] = ft_u;
	f[9] = ft_u2;
	f[10] = ft_x;
	f[11] = ft_x2;
	f[12] = ft_c;
	f[13] = ft_c2;
	f[14] = ft_b;
	f[15] = ft_r;
	f[16] = ft_g;
}

static int	ft_sub_printf(char *str, t_vars *vars)
{
	char	*beg_ptr;

	beg_ptr = str;
	vars->ret = 0;
	while(*str)
	{
		if(*str == '%')
		{
			var->ret += str - beg_ptr
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
	va_end(flags);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	t_vars		vars;
	int			ret;

	if (str == NULL)
		return (-1);
	va_start(vars.ap, str);
	ft_init_functions_tab(vars.f);
	ret = ft_sub_printf((char*)str, &vars) != -1 ? vars.ret : -1;
	return (0);
}
