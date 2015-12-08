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
# include <stdlib.h>
# include <wchar.h>

# include "libft.h"

# define NBOFTYPES 17
# define FT_TYPES "sSpdDioOuUxXcCbrg"
# define FT_PARSE "hljz-+ #.*"
# define FT_MODIF "hljz"
# define FT_FLAGS "-+ #"

typedef struct	s_options
{
	int			flags;
	int			len;
	int			precise;
	int			modif;
	int			type;
	int			zero;
}				t_options;

typedef struct	s_vars
{
	va_list		ap;
	int			(*f[NBOFTYPES])(t_options *, va_list *, int *);
	int			ret;
}				t_vars;

int				ft_printf(const char *str, ...);
void			ft_parse(char *str, int len, t_vars *vars);
void			ft_putspace(t_options *opt, int len, long long n);
void			ft_putsigned(int flags, long long n);
void			ft_putzero(t_options *opt, int len);

int				conv_s(t_options *opt, va_list *ap, int *ret);
int				conv_c(t_options *opt, va_list *ap, int *ret);
int				conv_c2(t_options *opt, va_list *ap, int *ret);
int				conv_d(t_options *opt, va_list *ap, int *ret);
int				conv_d2(t_options *opt, va_list *ap, int *ret);

int				ft_utfclen(wint_t c);
int				ft_utfnlen(wchar_t *s, int n);
int				ft_utflen(wchar_t *s);
int				ft_to_utf8(wint_t c, int bytes, unsigned char *mask);

# endif
