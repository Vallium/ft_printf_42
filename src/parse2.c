/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:04:45 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/09 15:04:52 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_searchpoint(char *str, int len)
{
	while (str[len] != '.' && len >= 0)
		--len;
	if (str[len] != '.')
		len = -1;
	return (len);
}

int				ft_flag(char *s1, char *s2, int len)
{
	int		i;
	int		j;
	char	*ts2;
	int		flags;

	i = 0;
	ts2 = s2;
	flags = 0;
	while (*s1)
	{
		s2 = ts2;
		j = 0;
		while (*s2 && j < len)
		{
			if (*s1 == *s2++)
				flags |= 1 << i;
			j++;
		}
		i++;
		s1++;
	}
	return (flags);
}

int				ft_zero(char *s1)
{
	while (*s1)
	{
		if (ft_isdigit(*s1) && (*s1 != '0' || *(s1 - 1) == '.'))
		{
			while (ft_isdigit(*s1))
				s1++;
		}
		else if (ft_isdigit(*s1))
			return (1);
		else
			s1++;
	}
	return (0);
}

int				ft_len(char *str, int len, va_list *ap)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < len)
	{
		if (str[i] == '.')
		{
			i++;
			while (ft_isdigit(str[i]) || str[i] == '*')
				i++;
		}
		if ((str[i] && ft_isdigit(str[i]) && ft_atoi(str + i) > 0) \
			|| str[i] == '*')
		{
			n = (str[i] == '*') ? va_arg(*ap, int) : ft_atoi(str + i);
			i += ft_longlen(n);
		}
		else
			i++;
	}
	return (n);
}
