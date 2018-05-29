/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisions_and_int_to_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:13:27 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:23:54 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int_to_char(int value)
{
	char *str;

	if ((str = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	if (value)
	{
		str[0] = value;
		str[1] = '\0';
	}
	else
	{
		free(str);
		str = ft_strdup("/nullchar/");
	}
	return (str);
}

char	*ft_handle_numeric_precision(int sign, t_specifiers *specifiers,
		char *str)
{
	char *tmp;

	if ((tmp = (char *)malloc(sizeof(char) * (specifiers->precision
								- ft_strlen(str) + 1))) == NULL)
		return (NULL);
	ft_memset(tmp, '0', specifiers->precision - ft_strlen(str));
	tmp[specifiers->precision - ft_strlen(str)] = '\0';
	if (sign == 1)
		str[0] = '0';
	str = ft_strjoin_free(tmp, str, 3);
	if (sign == 1)
		str = ft_strjoin_free("-", str, 2);
	return (str);
}

char	*ft_apply_precision(char *str, char c, t_specifiers *specifiers)
{
	int sign;

	if (str != NULL && (c == 'i' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
				|| c == 'x' || c == 'X' || c == 'D' || c == 'O' || c == 'U' ||
				c == 'p'))
	{
		sign = (str[0] == '-') ? 1 : 0;
		if (specifiers->precision == 0 && ft_strlen(str) == 1 && str[0] == '0')
		{
			free(str);
			str = ft_strdup("\0");
		}
		else if (specifiers->precision > (int)ft_strlen(str) - sign &&
				specifiers->precision > 0)
			str = ft_handle_numeric_precision(sign, specifiers, str);
	}
	return (str);
}
