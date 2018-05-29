/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:00:48 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:26:27 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_hashtag(t_specifiers *specifiers, char *str)
{
	if (ft_isflag(specifiers, '#') || specifiers->format == 'p')
	{
		if (specifiers->format == 'o' || specifiers->format == 'O')
		{
			if (str[0] != '0')
				str = ft_strjoin_free("0", str, 2);
		}
		if (specifiers->format == 'x')
		{
			if (str[ft_strlen(str) - 1] != '0' && str[0])
				str = ft_strjoin_free("0x", str, 2);
		}
		if (specifiers->format == 'X')
		{
			if (str[ft_strlen(str) - 1] != '0' && str[0])
				str = ft_strjoin_free("0X", str, 2);
		}
		if (specifiers->format == 'p')
			str = ft_strjoin_free("0x", str, 2);
	}
	return (str);
}

char	*ft_apply_plus_space(t_specifiers *specifiers, char *str)
{
	if ((specifiers->format == 'd' || specifiers->format == 'i' ||
				specifiers->format == 'D') && str[0] != '-' && str[0] != '+' &&
			ft_isflag(specifiers, '+'))
		str = ft_strjoin_free("+", str, 2);
	else if (ft_isflag(specifiers, ' ') && str[0] != ' ' &&
			(specifiers->format == 'd' || specifiers->format == 'i' ||
			specifiers->format == 'D') && str[0] != '-')
		str = ft_strjoin_free(" ", str, 2);
	return (str);
}

char	*ft_apply_sizemin_less(t_specifiers *specifiers, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (specifiers->sizemin > (int)ft_strlen(str) ||
			(ft_strcmp("/nullchar/", str) == 0 && specifiers->sizemin > 0))
	{
		if (ft_strcmp("/nullchar/", str) == 0)
			specifiers->sizemin = specifiers->sizemin +
			ft_strlen("/nullchar/") - 1;
		if ((tmp = (char *)malloc(sizeof(char) *
						(specifiers->sizemin - ft_strlen(str) + 1))) == NULL)
			return (NULL);
		ft_memset(tmp, ' ', specifiers->sizemin - ft_strlen(str));
		tmp[specifiers->sizemin - ft_strlen(str)] = '\0';
		if (ft_isflag(specifiers, '-'))
			tmp2 = ft_strjoin(str, tmp);
		else
			tmp2 = ft_strjoin(tmp, str);
		free(str);
		free(tmp);
		str = tmp2;
	}
	return (str);
}

char	*ft_apply_flags(char *str, t_specifiers *specifiers)
{
	str = ft_apply_0(specifiers, str);
	str = ft_apply_hashtag(specifiers, str);
	str = ft_apply_plus_space(specifiers, str);
	str = ft_apply_sizemin_less(specifiers, str);
	return (str);
}
