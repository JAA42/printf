/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:02:53 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:19:04 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_intmax_t_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	intmax_t	value;
	char		*tmp;
	int			n;

	n = 0;
	(void)specifiers;
	value = va_arg(*ap, intmax_t);
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

char	*ft_convert_jsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_intmax_t_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_uintmax_t_arg(specifiers, ap);
	return (str);
}

char	*ft_convert_size_t_arg(t_specifiers *specifiers,
		va_list *ap)
{
	char	*str;
	size_t	value;

	value = va_arg(*ap, size_t);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal((uintmax_t)value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal((uintmax_t)value, specifiers);
	return (str);
}

char	*ft_convert_size_t_looklike_arg(t_specifiers *specifiers, va_list *ap)
{
	char	*str;
	size_t	value;
	int		n;
	char	*tmp;

	n = 0;
	(void)specifiers;
	value = va_arg(*ap, size_t);
	if ((intmax_t)value == -9223372036854775800 - 8)
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

char	*ft_convert_zsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_size_t_looklike_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_size_t_arg(specifiers, ap);
	return (str);
}
