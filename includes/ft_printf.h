/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:39:48 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/17 13:39:51 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>



typedef struct	s_vars
{
	va_list		ap;
	int			(*f[NBOFTYPES])(t_options *, va_list *, int *);
	int			ret;
}				t_vars;

int			ft_printf(const char *str, ...);

# endif
