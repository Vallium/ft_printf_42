/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 20:54:31 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/08 20:54:44 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dectohex(char *hex, unsigned long n, int up)
{
	int		i;
	long	rem;

	i = 0;
	if (!n)
		hex[i++] = '0';
	while (n)
	{
		rem = n % 16;
		if (rem >= 10 && rem <= 15)
			hex[i] = (up) ? ft_toupper(FT_HEX[rem % 10]) : FT_HEX[rem % 10];
		else
			hex[i] = rem + '0';
		i++;
		n /= 16;
	}
	hex[i] = '\0';
	if (i > 1)
		ft_strrev(hex);
	return (0);
}
