/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:01:48 by avallois          #+#    #+#             */
/*   Updated: 2018/03/28 17:02:32 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(t_specifiers *specifiers, char chr)
{
	int i;

	i = 0;
	while (specifiers->flags[i] != '\0')
	{
		if (chr == specifiers->flags[i++])
			return (1);
	}
	return (0);
}

char	*ft_apply_0_plus_space(t_specifiers *specifiers, char *str)
{
	int i;
	int c;

	c = specifiers->format;
	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
		i++;
	}
	if ((c == 'd' || c == 'i' || c == 'D') && ft_isflag(specifiers, '+'))
	{
		if (str[0] != '-')
			str[0] = '+';
	}
	else if ((c == 'd' || c == 'i' || c == 'D') && ft_isflag(specifiers, ' '))
	{
		if (str[0] == '0')
			str[0] = ' ';
	}
	return (str);
}

char	*ft_handle_0_space(int size, t_specifiers *specifiers, char *str)
{
	char	*tmp;
	int		scale;
	int		c;

	c = specifiers->format;
	scale = (((c == 'x' || c == 'X') && ft_isflag(specifiers, '#')
				&& str[ft_strlen(str) - 1] != '0' &&
				str[0]) || c == 'p') ? 2 : 0;
	if ((tmp = (char *)malloc(sizeof(char) *
					(specifiers->sizemin - size - scale + 1))) == NULL)
		return (NULL);
	ft_memset(tmp, '0', specifiers->sizemin - size - scale);
	tmp[specifiers->sizemin - size - scale] = '\0';
	str = ft_strjoin_free(tmp, str, 3);
	ft_apply_0_plus_space(specifiers, str);
	return (str);
}

char	*ft_apply_0(t_specifiers *specifiers, char *str)
{
	char	c;
	int		size;

	c = specifiers->format;
	size = (c == 'c' && ft_strcmp("/nullchar/", str) == 0) ? 1 : ft_strlen(str);
	if (ft_isflag(specifiers, '0') && !ft_isflag(specifiers, '-'))
	{
		if ((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
					c == 'X' || c == 'D' || c == 'O' || c == 'U')
		&& specifiers->precision != -1)
			;
		else if (specifiers->sizemin > size)
			str = ft_handle_0_space(size, specifiers, str);
	}
	return (str);
}
