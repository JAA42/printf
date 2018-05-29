/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:07:56 by avallois          #+#    #+#             */
/*   Updated: 2018/05/17 14:58:44 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_str_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;
	char *tmp;

	str = va_arg(*ap, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (specifiers->precision >= 0)
	{
		tmp = ft_strsub(str, 0, specifiers->precision);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_convert_int_arg(t_specifiers *specifiers, va_list *ap)
{
	int		value;
	char	*str;
	char	format;

	str = NULL;
	value = va_arg(*ap, int);
	format = specifiers->format;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_intmax_t_itoa(value);
	else if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal((unsigned int)value);
	else if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa((unsigned int)value);
	else if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uint_decimal_to_hexadecimal(value, specifiers);
	else if (specifiers->format == 'c')
		str = ft_int_to_char(value);
	specifiers->format = format;
	return (str);
}

char	*ft_handle_long_limits_conv(intmax_t value, char *str)
{
	int n;

	n = 0;
	if (value == -9223372036854775800 - 8)
	{
		n = 1;
		value = value + 1;
		value = -value;
	}
	str = ft_intmax_t_itoa(value);
	if (n == 1)
	{
		str = ft_strjoin_free("-", str, 2);
		str[ft_strlen(str) - 1] = '8';
	}
	return (str);
}

char	*ft_convert_long_int_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	long int	value;

	str = NULL;
	value = va_arg(*ap, long int);
	if (specifiers->format == 'D')
		str = ft_handle_long_limits_conv(value, str);
	if (specifiers->format == 'O')
		str = ft_uintmax_t_decimal_to_octal(value);
	if (specifiers->format == 'U')
		str = ft_uintmax_t_itoa(value);
	str = ft_apply_precision(str, specifiers->format, specifiers);
	return (str);
}

char	*ft_convert_ptrvoid_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	long int	value;

	value = (long int)va_arg(*ap, void*);
	str = ft_uintmax_t_decimal_to_hexadecimal(value, specifiers);
	return (str);
}
