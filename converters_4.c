/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:07:06 by avallois          #+#    #+#             */
/*   Updated: 2018/03/28 17:07:38 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_widestr_arg(t_specifiers *specifiers, va_list *ap)
{
	wchar_t *str;

	str = va_arg(*ap, wchar_t*);
	(void)specifiers;
	return (NULL);
}

char	*ft_convert_wideint_arg(t_specifiers *specifiers, va_list *ap)
{
	wchar_t		value;
	char		*str;
	int			i;

	i = 0;
	value = va_arg(*ap, wint_t);
	(void)specifiers;
	if ((str = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str[0] = value;
	str[1] = '\0';
	return (str);
}

char	*ft_convert_signed_char_arg(t_specifiers *specifiers, va_list *ap)
{
	char		*str;
	signed char	value;

	value = va_arg(*ap, int);
	str = ft_intmax_t_itoa((intmax_t)value);
	(void)specifiers;
	return (str);
}

char	*ft_convert_unsigned_char_arg(t_specifiers *specifiers, va_list *ap)
{
	char			*str;
	unsigned char	value;

	value = va_arg(*ap, int);
	if (specifiers->format == 'o')
		str = ft_uintmax_t_decimal_to_octal((uintmax_t)value);
	if (specifiers->format == 'u')
		str = ft_uintmax_t_itoa(value);
	if (specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_uintmax_t_decimal_to_hexadecimal((uintmax_t)value, specifiers);
	return (str);
}

char	*ft_convert_hhsize_arg(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->format == 'd' || specifiers->format == 'i')
		str = ft_convert_signed_char_arg(specifiers, ap);
	if (specifiers->format == 'o' || specifiers->format == 'u' ||
			specifiers->format == 'x' || specifiers->format == 'X')
		str = ft_convert_unsigned_char_arg(specifiers, ap);
	return (str);
}
