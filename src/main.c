/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:10:39 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/26 13:19:09 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(int argc, char *argv[])
{
	(void)argc;

	ft_printf("%% => <%%>\n");
	ft_printf("c => <%c>\n", argv[1][0]);
	ft_printf("s => <%s>\n", argv[1]);
	ft_printf("d => <%d>\n", 42);

	return 0;
}
