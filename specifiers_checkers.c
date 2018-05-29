/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_checkers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:12:09 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 14:36:50 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(const char *str, t_specifiers *specifiers)
{
	if (specifiers->flags == NULL)
		specifiers->flags = ft_strdup("\0");
	if (str[0] == '#' || (str[0] == '0' && str[-1] != '.' &&
	!ft_isdigit(str[-1])) || str[0] == '-' || str[0] == ' ' || str[0] == '+')
	{
		if (str[0] == '#')
			specifiers->flags = ft_strjoin_free(specifiers->flags, "#", 1);
		else if (str[0] == '0' && str[-1] != '.' && !ft_isdigit(str[-1]))
			specifiers->flags = ft_strjoin_free(specifiers->flags, "0", 1);
		else if (str[0] == '-')
			specifiers->flags = ft_strjoin_free(specifiers->flags, "-", 1);
		else if (str[0] == ' ')
			specifiers->flags = ft_strjoin_free(specifiers->flags, " ", 1);
		else if (str[0] == '+')
			specifiers->flags = ft_strjoin_free(specifiers->flags, "+", 1);
		return (1);
	}
	return (0);
}

int		ft_check_size_min(char chr, t_specifiers *specifiers)
{
	char tmp[2];

	if (ft_isdigit(chr))
	{
		tmp[0] = chr;
		tmp[1] = '\0';
		specifiers->sizemin = (10 * specifiers->sizemin) + ft_atoi(tmp);
		return (1);
	}
	return (0);
}

int		ft_check_precision(char chr, t_specifiers *specifiers)
{
	char tmp[2];

	if (ft_isdigit(chr) || chr == '.')
	{
		if (chr == '.')
		{
			if (specifiers->precision == -1)
				specifiers->precision = 0;
			else
				specifiers->precision = 0;
		}
		else
		{
			tmp[0] = chr;
			tmp[1] = '\0';
			specifiers->precision = (10 * specifiers->precision) + ft_atoi(tmp);
		}
		return (1);
	}
	return (0);
}

int		ft_check_size_modifier(const char *str, t_specifiers *specifiers)
{
	if (str[0] == 'h' || str[0] == 'l' || str[0] == 'j' || str[0] == 'z')
	{
		if (str[0] == 'h')
		{
			if (str[1] == 'h')
				specifiers->sizemodifier = 'H';
			else if (str[-1] != 'h')
				specifiers->sizemodifier = 'h';
		}
		else if (str[0] == 'l')
		{
			if (str[1] == 'l')
				specifiers->sizemodifier = 'L';
			else if (str[-1] != 'l')
				specifiers->sizemodifier = 'l';
		}
		else if (str[0] == 'j')
			specifiers->sizemodifier = 'j';
		else if (str[0] == 'z')
			specifiers->sizemodifier = 'z';
		return (1);
	}
	return (0);
}

int		ft_check_format(char chr, t_specifiers *specifiers)
{
	specifiers->format = chr;
	return (1);
}
