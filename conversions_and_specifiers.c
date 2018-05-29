/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_and_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:09:06 by avallois          #+#    #+#             */
/*   Updated: 2018/05/15 18:24:11 by avallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_get_specifiers(const char *str, t_specifiers *specifiers)
{
	int newstate;
	int state;
	int i;

	state = 0;
	i = 0;
	newstate = 0;
	while (state != 4 && str[i] != '\0')
	{
		state = newstate;
		if (ft_check_flags(&str[i], specifiers))
			newstate = 0;
		else if (ft_check_size_modifier(&str[i], specifiers))
			newstate = 1;
		else if ((state == 0 || state == 1) &&
		!ft_check_size_min(str[i], specifiers))
			newstate = 2;
		else if (state == 2 && !ft_check_precision(str[i], specifiers))
			newstate = 3;
		else if (state == 3 && ft_check_format(str[i], specifiers))
			newstate = 4;
		if (state == newstate)
			i++;
	}
}

t_specifiers	*ft_init_specifiers(void)
{
	t_specifiers	*specifiers;

	if ((specifiers = (t_specifiers*)malloc(sizeof(t_specifiers))) == NULL)
		return (NULL);
	specifiers->flags = NULL;
	specifiers->sizemin = 0;
	specifiers->precision = -1;
	specifiers->sizemodifier = '\0';
	specifiers->format = '\0';
	return (specifiers);
}

char			*ft_get_spec_conversion(t_specifiers *specifiers, va_list *ap)
{
	char *str;

	str = NULL;
	if (specifiers->sizemodifier == 'H')
		str = ft_convert_hhsize_arg(specifiers, ap);
	if (specifiers->sizemodifier == 'h')
		str = ft_convert_hsize_arg(specifiers, ap);
	if (specifiers->sizemodifier == 'l')
		str = ft_convert_lsize_arg(specifiers, ap);
	if (specifiers->sizemodifier == 'L')
		str = ft_convert_llsize_arg(specifiers, ap);
	if (specifiers->sizemodifier == 'j')
		str = ft_convert_jsize_arg(specifiers, ap);
	if (specifiers->sizemodifier == 'z')
		str = ft_convert_zsize_arg(specifiers, ap);
	str = ft_apply_precision(str, specifiers->format, specifiers);
	return (str);
}

char			*ft_get_conversion(t_specifiers *specifiers, va_list *ap)
{
	char *str;
	char c;

	c = specifiers->format;
	str = NULL;
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
	c == 'X' || c == 'c')
		str = ft_convert_int_arg(specifiers, ap);
	else if (c == 'D' || c == 'O' || c == 'U')
		str = ft_convert_long_int_arg(specifiers, ap);
	else if (c == 's')
		str = ft_convert_str_arg(specifiers, ap);
	else if (c == 'p')
		str = ft_convert_ptrvoid_arg(specifiers, ap);
	else if (c == 'S')
		str = ft_convert_widestr_arg(specifiers, ap);
	else if (c == 'C')
		str = ft_convert_wideint_arg(specifiers, ap);
	else if (c == '%')
		str = ft_strdup("%");
	str = ft_apply_precision(str, c, specifiers);
	return (str);
}
