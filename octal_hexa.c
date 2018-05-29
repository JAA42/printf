/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:10:51 by avallois          #+#    #+#             */
/*   Updated: 2018/05/17 16:19:36 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uintmax_t_decimal_to_octal(uintmax_t value)
{
	char *str;
	char *rest;

	rest = NULL;
	if (value == 0)
		return (ft_strdup("0"));
	else
		str = ft_strdup("\0");
	while (value != 0)
	{
		rest = ft_intmax_t_itoa(value % 8);
		str = ft_strjoin_free(rest, str, 2);
		free(rest);
		value = value / 8;
	}
	return (str);
}

char	*ft_keep_rest_uint_hexa(unsigned int value, t_specifiers *specifiers)
{
	unsigned int	rest;
	char			*tmp;
	unsigned int	asciinb;

	asciinb = (specifiers->format == 'x') ? 96 : 64;
	tmp = NULL;
	rest = value % 16;
	if (rest > 9)
	{
		if ((tmp = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		tmp[0] = asciinb + (rest - 9);
		tmp[1] = '\0';
	}
	else
		tmp = ft_intmax_t_itoa(rest);
	return (tmp);
}

char	*ft_uint_decimal_to_hexadecimal(unsigned int value,
		t_specifiers *specifiers)
{
	char *hexastr;
	char *tmp;
	char *tmp2;

	hexastr = ft_strdup("\0");
	if (value == 0)
	{
		free(hexastr);
		return (ft_strdup("0"));
	}
	while (value != 0)
	{
		tmp = ft_keep_rest_uint_hexa(value, specifiers);
		tmp2 = ft_strjoin(tmp, hexastr);
		free(tmp);
		free(hexastr);
		hexastr = tmp2;
		value = value / 16;
	}
	return (hexastr);
}

char	*ft_keep_rest_uintmax_t_hexa(uintmax_t value, t_specifiers *specifiers)
{
	uintmax_t	rest;
	char		*tmp;
	int			asciinb;

	asciinb = (specifiers->format == 'x' || specifiers->format == 'p') ?
	96 : 64;
	tmp = NULL;
	rest = value % 16;
	if (rest > 9)
	{
		if ((tmp = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		tmp[0] = asciinb + (rest - 9);
		tmp[1] = '\0';
	}
	else
		tmp = ft_intmax_t_itoa(rest);
	return (tmp);
}

char	*ft_uintmax_t_decimal_to_hexadecimal(uintmax_t value,
		t_specifiers *specifiers)
{
	char *hexastr;
	char *tmp;
	char *tmp2;

	hexastr = ft_strdup("\0");
	if (value == 0)
	{
		free(hexastr);
		return (ft_strdup("0"));
	}
	while (value != 0)
	{
		tmp = ft_keep_rest_uintmax_t_hexa(value, specifiers);
		tmp2 = ft_strjoin(tmp, hexastr);
		free(tmp);
		free(hexastr);
		hexastr = tmp2;
		value = value / 16;
	}
	return (hexastr);
}
