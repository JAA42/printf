/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:14:28 by avallois          #+#    #+#             */
/*   Updated: 2018/03/28 17:21:55 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct		s_specifiers
{
	char	*flags;
	int		sizemin;
	int		precision;
	char	sizemodifier;
	char	format;
}					t_specifiers;

t_specifiers		*ft_init_specifiers(void);
int					ft_check_flags(const char *str, t_specifiers *specifiers);
int					ft_isflag(t_specifiers *specifiers, char chr);
int					ft_check_size_min(char chr, t_specifiers *specifiers);
int					ft_check_precision(char chr, t_specifiers *specifiers);
int					ft_check_size_modifier(const char *str, t_specifiers
					*specifiers);
int					ft_check_format(char chr, t_specifiers *specifiers);
void				ft_get_specifiers(const char *str, t_specifiers
					*specifiers);
char				*ft_int_to_char(int value);
char				*ft_convert_str_arg(t_specifiers *specifiers, va_list *ap);
char				*ft_uintmax_t_decimal_to_octal(uintmax_t value);
char				*ft_keep_rest_uint_hexa(unsigned int value, t_specifiers
					*specifiers);
char				*ft_uint_decimal_to_hexadecimal(unsigned int value,
					t_specifiers *specifiers);
char				*ft_keep_rest_uintmax_t_hexa(uintmax_t value, t_specifiers
					*specifiers);
char				*ft_uintmax_t_decimal_to_hexadecimal(uintmax_t value,
					t_specifiers *specifiers);
char				*ft_handle_numeric_precision(int sign, t_specifiers
					*specifiers,
					char *str);
char				*ft_apply_precision(char *str, char c, t_specifiers
					*specifiers);
char				*ft_convert_int_arg(t_specifiers *specifiers, va_list *ap);
char				*ft_handle_long_limits_conv(intmax_t value, char *str);
char				*ft_convert_long_int_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_ptrvoid_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_widestr_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_wideint_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_signed_char_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_unsigned_char_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_hhsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_short_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_unsigned_short_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_hsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_long_arg(t_specifiers *specifiers, va_list *ap);
char				*ft_convert_unsigned_long_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_lsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_long_long_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_unsigned_long_long_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_llsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_uintmax_t_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_intmax_t_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_jsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_convert_size_t_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_size_t_looklike_arg(t_specifiers *specifiers,
					va_list *ap);
char				*ft_convert_zsize_arg(t_specifiers *specifiers, va_list
					*ap);
char				*ft_get_spec_conversion(t_specifiers *specifiers, va_list
					*ap);
char				*ft_get_conversion(t_specifiers *specifiers, va_list *ap);
char				*ft_apply_0_plus_space(t_specifiers *specifiers, char *str);
char				*ft_handle_0_space(int size, t_specifiers *specifiers,
					char *str);
char				*ft_apply_0(t_specifiers *specifiers, char *str);
char				*ft_apply_hashtag(t_specifiers *specifiers, char *str);
char				*ft_apply_plus_space(t_specifiers *specifiers, char *str);
char				*ft_apply_sizemin_less(t_specifiers *specifiers, char *str);
char				*ft_apply_flags(char *str, t_specifiers *specifiers);
int					ft_putstrprintf(char *s);
char				*ft_add_char(char *strlast, char c);
char				*ft_apply_converter(char *strlast, va_list *ap,
					t_specifiers *specifiers);
char				*ft_add_conversion(int *i, char *str, va_list *ap, char
					*strlast);
int					ft_printf(const char *str, ...);
#endif
