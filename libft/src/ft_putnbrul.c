/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:24:26 by aalliot           #+#    #+#             */
/*   Updated: 2015/12/08 17:29:45 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrul(unsigned long n)
{
	if (n > 9)
	{
		ft_putnbrul(n / 10);
		ft_putnbrul(n % 10);
	}
	else
	{
		ft_putchar(48 + n);
	}
}