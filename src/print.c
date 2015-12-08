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
