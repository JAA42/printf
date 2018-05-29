/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:59:50 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:24:45 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstrprintf(char *s)
{
	int		i;
	char	*tmp;
	int		n;

	tmp = s;
	n = 0;
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (&s[i] == ft_strstr(&s[i], "/nullchar/"))
			{
				n++;
				ft_putchar(0);
				s = s + ft_strlen("/nullchar/");
			}
			else
				ft_putchar(s[i++]);
		}
		free((void*)tmp);
	}
	return ((ft_strlen("/nullchar/") - 1) * n);
}

char	*ft_add_char(char *strlast, char c)
{
	char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	strlast = ft_strjoin_free(strlast, tmp, 1);
	return (strlast);
}

char	*ft_apply_converter(char *strlast, va_list *ap,
		t_specifiers *specifiers)
{
	char *conversion;

	conversion = NULL;
	conversion = ft_get_spec_conversion(specifiers, ap);
	if (!conversion)
		conversion = ft_get_conversion(specifiers, ap);
	if (!conversion)
	{
		if ((conversion = (char*)malloc(sizeof(char) * 2)) == NULL)
			return (0);
		conversion[0] = specifiers->format;
		conversion[1] = '\0';
	}
	conversion = ft_apply_flags(conversion, specifiers);
	if (conversion)
		strlast = ft_strjoin_free(strlast, conversion, 3);
	return (strlast);
}

char	*ft_add_conversion(int *i, char *str, va_list *ap, char *strlast)
{
	t_specifiers *specifiers;

	specifiers = ft_init_specifiers();
	ft_get_specifiers(&str[*i + 1], specifiers);
	if (specifiers->format)
	{
		strlast = ft_apply_converter(strlast, ap, specifiers);
		*i = *i + 1;
		while (str[*i] != specifiers->format)
			*i = *i + 1;
		free(specifiers->flags);
		free(specifiers);
	}
	return (strlast);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		ap;
	char		*strlast;

	i = 0;
	va_start(ap, str);
	strlast = ft_strdup("\0");
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			strlast = ft_add_conversion(&i, (char*)str, &ap, strlast);
		else
			strlast = ft_add_char(strlast, str[i]);
		i++;
	}
	va_end(ap);
	return (ft_strlen(strlast) - ft_putstrprintf(strlast));
}
