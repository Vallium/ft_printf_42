/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:04:05 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/08 16:04:08 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putsigned(int flags, long long n)
{
	if (n < 0)
		write(1, "-", 1);
	else if (flags & 2)
		write(1, "+", 1);
	else
		write(1, " ", 1);
}

void		ft_putzero(t_options *opt, int len)
{
	char	*str;
	int		size;
	int		i;

	size = ((len < 0) ? 1 : 0) + opt->precise - len;
	if ((str = (char*)malloc(sizeof(char*) * size)) == NULL)
		return ;
	i = 0;
	while (i < size)
		str[i++] = '0';
	str[i] = '\0';
	write(1, str, size);
	free(str);
}

void		ft_putspace(t_options *opt, int len, long long n)
{
	char	*str;
	int		size;
	int		i;
	char	c;

	size = (opt->len > len) ? opt->len - len : 0;
	if (opt->type == 3 && n < 0 && opt->precise == -1 && opt->zero \
		&& !(opt->flags & 1))
	{
		opt->precise += opt->len;
		return ;
	}
	if ((str = (char*)malloc(sizeof(char*) * size)) == NULL)
		return ;
	if (opt->type >= 2 && opt->type <= 11 && opt->precise != -1)
		c = ' ';
	else
		c = (opt->zero && !(opt->flags & 1)) ? '0' : ' ';
	i = 0;
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	write(1, str, size);
	free(str);
}
