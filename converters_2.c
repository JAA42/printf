/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:04:27 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:19:19 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_lsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_long_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_unsigned_long_arg(specifiers, ap);
	return (str);
}

char	*ft_convert_long_long_arg(t_specifiers *specifiers, va_list *ap)
{
	char			*str;
	long long int	value;
	int				n;
	char			*tmp;

	n = 0;
	(void)specifiers;
	value = va_arg(*ap, long long int);
	if (value == -9223372036854775800 - 8)
	{
		n = 1;
		value = value + 1;
		value = -value;
	}
	str = ft_intmax_t_itoa(value);
	if (n == 1)
	{
		tmp = ft_strjoin("-", str);
		free(str);
		str = tmp;
		str[ft_strlen(str) - 1] = '8';
	}
	return (str);
}

char	*ft_convert_unsigned_long_long_arg(t_specifiers *specifiers,
		va_list *ap)
{
	char					*str;
	unsigned long long int	value;

	value = va_arg(*ap, unsigned long long int);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal(value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal((uintmax_t)value, specifiers);
	return (str);
}

char	*ft_convert_llsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_long_long_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_unsigned_long_long_arg(specifiers, ap);
	if (specifiers->format == 'c')
		str = ft_convert_wideint_arg(specifiers, ap);
	return (str);
}

char	*ft_convert_uintmax_t_arg(t_specifiers *specifiers,
		va_list *ap)
{
	char		*str;
	uintmax_t	value;

	value = va_arg(*ap, uintmax_t);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal(value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal(value, specifiers);
	return (str);
}
