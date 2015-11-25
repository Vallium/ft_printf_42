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
	int		i;

	i = 0;
	while (str[i] && (ft_isdigit(str[i]) || ft_strchr(FT_PARSE, str[i])))
		++i;
	if (str[i])
	{
		ft_parse(str, i, vars);
		++i;
	}
	return (i);
}

static void		ft_init_functions_tab(int (**f)(t_options *, va_list *, int *))
{
	(void)f[0]; // = ft_s;
	(void)f[1] ;// = ft_s2;
	(void)f[2]; // = ft_p;
	(void)f[3]; // = ft_d;
	(void)f[4] ;// = ft_d2;
	(void)f[5]; // = ft_d;
	(void)f[6]; // = ft_o;
	(void)f[7] ;// = ft_o2;
	(void)f[8]; // = ft_u;
	(void)f[9] ;// = ft_u2;
	(void)f[10]; // = ft_x;
	(void)f[11] ;// = ft_x2;
	(void)f[12]; // = ft_c;
	(void)f[13] ;// = ft_c2;
	(void)f[14]; // = ft_b;
	(void)f[15]; // = ft_r;
	(void)f[16]; // = ft_g;
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
			vars->ret += str - beg_ptr;
			if (vars->ret > 0)
				write(1, beg_ptr, str - beg_ptr);
			// str += ft_parse_var(str + 1, vars) + 1;
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
