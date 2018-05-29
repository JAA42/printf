/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:28 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:19:28 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_short_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	short int	value;

	(void)specifiers;
	value = va_arg(*ap, int);
	str = ft_intmax_t_itoa((intmax_t)value);
	return (str);
}

char	*ft_convert_unsigned_short_arg(t_specifiers *specifiers, va_list *ap)
{
	char				*str;
	unsigned short int	value;

	value = va_arg(*ap, unsigned int);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal((uintmax_t)value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal((uintmax_t)value, specifiers);
	return (str);
}

char	*ft_convert_hsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_short_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_unsigned_short_arg(specifiers, ap);
	return (str);
}

char	*ft_convert_long_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	long int	value;
	char		*tmp;
	int			n;

	(void)specifiers;
	n = 0;
	value = va_arg(*ap, long int);
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

char	*ft_convert_unsigned_long_arg(t_specifiers *specifiers, va_list *ap)
{
	char				*str;
	unsigned long int	value;

	value = va_arg(*ap, unsigned long int);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal(value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal((uintmax_t)value, specifiers);
	return (str);
}
